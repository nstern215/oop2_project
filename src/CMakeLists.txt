target_sources (${CMAKE_PROJECT_NAME} PRIVATE "main.cpp"
												"Controller.cpp"
												"Resources.cpp"
												"Player.cpp"
												"Floor.cpp"
												"Tower.cpp"
												"FloorGenerator.cpp"

												#components
												"Components/BaseComponent.cpp"
												"Components/GameComponent.cpp"
												"Components/WelcomeComponent.cpp"
												"Components/TutorialComponent.cpp"
												"Components/MenuComponent.cpp"

												#views
												"Views/BaseView.cpp"
												"Views/TextView.cpp"
												"Views/PlayerView.cpp"
												"Views/FloorView.cpp"
												)