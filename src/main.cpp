/****************************************************************************
**
** Copyright (C) 2015 ProVR
**
****************************************************************************/

#include <cstdlib>
#include <string>
#include <fstream>
#include <motorcar.h>


int main(int argc, char *argv[])
{
    std::string home(getenv("HOME"));
    std::string sessionFile(home + "/.config/provr/session");

    motorcar::Scene *scene = new motorcar::Scene();

    motorcar::Compositor *compositor = motorcar::Compositor::createCompositor(argc, argv, scene) ;
    scene->setCompositor(compositor);

    scene->setWindowManager( new motorcar::WindowManager(scene, compositor->defaultSeat()));

    motorcar::OpenGLContext *context = compositor->getContext();

    motorcar::Skeleton *skeleton = new motorcar::Skeleton(scene);


    std::cout << "Using Default Display" << std::endl;
    float camToDisplayDistance = 0.1f;
    motorcar::Display *display = new motorcar::Display(context, glm::vec2(0.325f, 0.1f), scene, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.8f, 1.25f))                                                                                                 * glm::rotate(glm::mat4(1.0f), -25.0f, glm::vec3(1.0f, 0.0f, 0.0f)));
    display->addViewpoint(new motorcar::ViewPoint( .01f, 100.0f, display, display, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, camToDisplayDistance))));
    compositor->setDisplay(display);
    scene->addDisplay(compositor->display());


    if((std::ifstream(sessionFile)).good()) {
        std::cout << "Starting session"<<std::endl;
        std::system((sessionFile + "&").c_str());
    } else {
        std::cout << "No session file; starting default session"<<std::endl;
        std::system("vte2_90 &");
    }

    std::cout << "Starting Compositor"<<std::endl;

    int result = compositor->start();

    delete scene;

    return result;
}
