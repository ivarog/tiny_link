#pragma once
#include <blah.h>
#include "world.h"

using namespace Blah;

namespace TL
{
	class Game
	{
	public:
		static constexpr int width = 240;
		static constexpr int height = 135;
		static constexpr int tile_width = 8;
		static constexpr int tile_height = 8;
		static constexpr int columns = width / tile_width;
		static constexpr int rows = height / tile_height + 1;

		World world;
		FrameBufferRef buffer;
		Batch batch;
		Point room;
		Vec2 camera;

		void load_room(Point cell);
		void startup();
		void shutdown();
		void update();
		void render();

	private:
		bool m_draw_colliders;
		bool m_transition = false;
		float m_next_ease;
		Point m_next_room;
		Point m_last_room;
		Vector<Entity*> m_last_entities;
	};
}