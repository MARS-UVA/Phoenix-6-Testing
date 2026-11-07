#include <ctre/phoenix6/TalonFXS.hpp>
#include <ctre/phoenix6/configs/Configuration.hpp>
#include <ctre/phoenix6/controls/DutyCycleOut.hpp>
#include <ctre/phoenix6/unmanaged/Unmanaged.hpp>

#include <chrono>
#include <thread>

using namespace ctre::phoenix6;

int main() {
    hardware::TalonFXS motor{20, "*"};

    while (true) {
	ctre::phoenix::unmanaged::FeedEnable(10);
	motor.SetControl(controls::DutyCycleOut{0.5});
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

