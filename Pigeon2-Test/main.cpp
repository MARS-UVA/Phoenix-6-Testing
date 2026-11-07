#include <ctre/phoenix6/Pigeon2.hpp>
#include <ncurses.h>

#include <chrono>
#include <iostream>
#include <thread>

using ctre::phoenix6::hardware::Pigeon2;

int main() 
{
	Pigeon2 pigeon{30, "*"};

	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	refresh();

	while (true) {
		clear();

        	double yaw = pigeon.GetYaw().GetValueAsDouble();
        	double pitch = pigeon.GetPitch().GetValueAsDouble();
        	double roll = pigeon.GetRoll().GetValueAsDouble();
        	double angularVelocity = pigeon.GetAngularVelocityZWorld().GetValueAsDouble();

		mvprintw(0, 1, "Pigeon 2.0 Test, press q to quit");
		mvprintw(2, 1, "Yaw: %lf deg", yaw);
		mvprintw(3, 1, "Pitch: %lf deg", pitch);
		mvprintw(4, 1, "Roll: %lf deg", roll);
		mvprintw(5, 1, "Angular Velocity: %lf deg", angularVelocity);

		if (getch() == 'q') {
			endwin();
			return 0;
		}

		refresh();

        	std::this_thread::sleep_for(std::chrono::milliseconds(100));
    	}
}

