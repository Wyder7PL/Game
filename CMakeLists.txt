cmake_minimum_required(VERSION 3.1)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(Game)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/SFML/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)
add_executable(Game main.cpp 
	"Anoyher/include/Keyboard.h" "Anoyher/include/GraphicObject.h" "Anoyher/include/PhysicObject.h" "Anoyher/include/GraphicControler.hpp" "Anoyher/include/PhysicControler.hpp" Anoyher/mainControler.hpp	Anoyher/src/Keyboard.cpp Anoyher/src/GraphicObject.cpp Anoyher/src/PhysicObject.cpp Anoyher/src/GraphicControler.cpp Anoyher/src/PhysicControler.cpp Anoyher/src/mainControler.cpp
	
	CustomBuildings/CustomBuildings.h CustomBuildings/CustomBuildings.cpp CustomBuildings/Tavern.h CustomBuildings/Tavern.cpp
	
	CustomGUIObjects/GUIHPViewer.cpp CustomGUIObjects/GUIHPViewer.h CustomGUIObjects/Menu.cpp CustomGUIObjects/Menu.h CustomGUIObjects/MultiButton.cpp CustomGUIObjects/MultiButton.h CustomGUIObjects/RandomGUIObjects.cpp CustomGUIObjects/RandomGUIObjects.h
	
	"include/AddObject.h" "include/Building.h" "include/Construction.h" "include/Control.h" "include/Creature.h" "include/Economy.h" "include/Fraction.h" "include/Functions.h" "include/GUI.h" "include/GUIObjectCreateButton.h" "include/GUIObjectInfoElement.h" "include/Ground.h" "include/HP.h" "include/Item.h" "include/Map.h" "include/Markable.h" "include/Materials.h" "include/NaturalResource.h" "include/ObjectInfo.h" "include/PreBuilding.h" "include/SafePointer.h" "include/Skill.h" "include/Unit.h" "include/WrapedText.h" "include/projectile.h"
	
	src/AddObject.cpp src/Building.cpp src/Construction.cpp src/Control.cpp src/Creature.cpp src/Economy.cpp src/Fraction.cpp src/Functions.cpp src/GUI.cpp src/GUIObjectCreateButton.cpp src/GUIObjectInfoElement.cpp src/Ground.cpp src/HP.cpp src/Item.cpp src/Map.cpp src/Markable.cpp src/Materials.cpp src/NaturalResource.cpp src/ObjectInfo.cpp src/PreBuilding.cpp src/SafePointer.cpp src/Skill.cpp src/Unit.cpp src/WrapedText.cpp src/projectile.cpp
	
	OtterCustomThings/GlobalEvents.h OtterCustomThings/GlobalEvents.cpp OtterCustomThings/Tasks.h OtterCustomThings/Tasks.cpp
	
	Races/TestRace.h Races/TestRace.cpp
	
	Textures/Textures.h Textures/Textures.cpp
	
	Fonts/Fonts.cpp Fonts/Fonts.h
)
target_link_libraries(Game sfml-graphics sfml-window sfml-system)