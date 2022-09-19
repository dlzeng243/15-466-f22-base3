#include "Mode.hpp"

#include "Scene.hpp"
#include "Sound.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} a_left, d_right, s_down, w_up, left, right, space;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;


	glm::vec3 get_leg_tip_position();

	//music coming from the tip of the leg (as a demonstration):
	std::shared_ptr< Sound::PlayingSample > leg_tip_loop;
	
	//camera:
	Scene::Camera *camera = nullptr;
	// Coins
	Scene::Transform blue_transform = Scene::Transform();
	Scene::Drawable blue_draw = Scene::Drawable(&blue_transform);

	Scene::Transform green_transform = Scene::Transform();
	Scene::Drawable green_draw = Scene::Drawable(&green_transform);
	
	Scene::Transform red_transform = Scene::Transform();
	Scene::Drawable red_draw = Scene::Drawable(&red_transform);

	//initial: rgb, rgb, rgb, etc. (0 red, 1 green, 2 red) mod 3
	//hope to change to: rgb, bgr, rgb, etc. (0 and 5 red, 1 and 4 green, 2 and 3 blue) mod 6
	int current_coin = 0;
	
	// ranges from 0 to 7
	int column = 3;
	const int w = 8;
	const int h = 6;

	// 2d array of ints representing the board (-1 means no coin put in yet)
	int arr[6][8] = {{-1, -1, -1, -1, -1, -1, -1, -1}, 
					 {-1, -1, -1, -1, -1, -1, -1, -1}, 
					 {-1, -1, -1, -1, -1, -1, -1, -1},
					 {-1, -1, -1, -1, -1, -1, -1, -1},
					 {-1, -1, -1, -1, -1, -1, -1, -1},
					 {-1, -1, -1, -1, -1, -1, -1, -1}};

	// 1d array of heights so we don't have to check arr every time
	int heights[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	// game done state
	std::string name(int coin);
	bool check_win(int row, int col);
	bool finished = false;
	bool drawed = false;
	std::string winner = "";

	// sounds
	Sound::Sample red_coin;
	Sound::Sample green_coin;
	Sound::Sample blue_coin;
	void play_coins(int row, int col);
};