cmake_minimum_required(VERSION 2.8.3)
project(homer_robbie_architecture)

find_package(catkin REQUIRED COMPONENTS
	roscpp
	cmake_modules
)

find_package(OpenCV REQUIRED)

catkin_package(
        INCLUDE_DIRS include
		LIBRARIES homerConfig homerImageHelpers homerMath homerSingleton homerStateMachine homerThread homerString
		CATKIN_DEPENDS roscpp
)


include_directories(
	include
	${catkin_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
)

add_library(homerImageHelpers
	src/Workers/ImageHelpers/ImageMaskCV.cpp
)
target_link_libraries(homerImageHelpers homerMath)

add_library(homerMath
	src/Workers/Math/Line2D.cpp
	src/Workers/Math/Polygon2D.cpp
	src/Workers/Math/misc.cpp
	src/Workers/Math/Transformation2D.cpp
	src/Workers/Math/mat3.cpp
	src/Workers/Math/Circle2D.cpp
	src/Workers/Math/Pose.cpp
	src/Workers/Math/Obb2D.cpp
	src/Workers/Math/Matrix.cpp
	src/Workers/Math/Math.cpp
	src/Workers/Math/Point2D.cpp
	src/Workers/Math/Vector3D.cpp
	src/Workers/Math/Homography.cpp
)

add_library(homerString
	src/Workers/String/String.cpp
)

add_library(homerConfig
	src/Architecture/Config/Config.cpp
)
target_link_libraries(homerConfig tinyxml homerThread)

add_library(homerSingleton
	src/Architecture/Singleton/Clock.cpp
	src/Architecture/Singleton/SequenceNumber.cpp
)
target_link_libraries(homerSingleton homerThread)

add_library(homerStateMachine
	src/Architecture/StateMachine/StateMachine.cpp
)
target_link_libraries(homerStateMachine homerSingleton)

add_library(homerThread
    src/Architecture/Thread/Mutex.cpp
    src/Architecture/Thread/Thread.cpp
    src/Architecture/Thread/Condition.cpp
)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
install(DIRECTORY include/${PROJECT_NAME}/ DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})
