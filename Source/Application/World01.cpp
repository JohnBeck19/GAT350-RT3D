#include "World01.h"
#include "Framework/Framework.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

namespace nc
{
    bool World01::Initialize()
    {
        for (int i = 0; i < 10; i++)
        {
            m_pos.push_back(glm::vec2{ randomf(-0.25f, 0.25f), randomf(-0.25f, 0.25f) });
        }
        return true;
    }

    void World01::Shutdown()
    {
    }

    void World01::Update(float dt)
    {

        m_angle += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_Q) ? -dt*360 : 0;
        m_angle += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_E) ? +dt*360 : 0;
        for (int i = 0; i < 10; i++) {

            m_pos[i].x += dt * random(-1, 1);
            m_pos[i].y += dt * random(-1, 1);
            m_pos[i].x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_A) ? -dt : 0;
            m_pos[i].x += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_D) ? +dt : 0;
            m_pos[i].y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_S) ? -dt : 0;
            m_pos[i].y += ENGINE.GetSystem<InputSystem>()->GetKeyDown(SDL_SCANCODE_W) ? +dt : 0;

        }
        m_time += dt;

    }

    void World01::Draw(Renderer& renderer)
    {
        // pre-render

        renderer.BeginFrame();

        for (int i = 0; i < 10; i++) {
            // render
            glPushMatrix();
            glTranslatef(m_pos[i].x, m_pos[i].y, 0);
            glRotatef(m_angle, 1, 1, 1);
            glScalef(sin((m_time * 5) + 1) * 0.2f, 1, 1);

            glBegin(GL_QUADS);

            glColor3f(1, 0, 1);
            glVertex2f(-0.25f, -0.25f);


            glColor3f(0, 1, 1);
            glVertex2f(0.25f, -0.25f);

            glColor3f(1, 1, 1);
            glVertex2f(0.25f, 0.25f);

            glColor3f(0, 1, 1);
            glVertex2f(-0.25f, 0.25f);
            glEnd();

        glPopMatrix();
        }
        // post-render
        renderer.EndFrame();
    }
}
