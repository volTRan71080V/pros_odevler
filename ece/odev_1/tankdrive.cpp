#include "okapi/api.hpp"
using namespace okapi;

std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
        .withMotors({1, 2, 3, 4}, {-5, -6, -7, -8})
        .withDimensions(AbstractMotor::gearset::green,
                        {{4_in, 13.5_in}, imev5GreenTPR})
        .withOdometry()
        .buildOdometry();

void OpControl() {
  while (true) {
    drive->getModel()->tank(controller.getAnalog(ControllerAnalog::leftY),
                            controller.getAnalog(ControllerAnalog::rightX));
    pros::delay(10);
  }
}
