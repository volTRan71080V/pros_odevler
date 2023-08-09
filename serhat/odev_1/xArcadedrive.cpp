#include "okapi/api.hpp"
using namespace okapi;

std::shared_ptr<ChassisController> drive =
    ChassisControllerBuilder()
        .withMotors(1, -2, -3, 4)
        .withDimensions(AbstractMotor::gearset::green,
                        {{4_in, 13.5_in}, imev5GreenTPR})
        .withOdometry()
        .buildOdometry();

void OpControl() {
  while (true) {
    drive->getModel()->xArcade(controller.getAnalog(ControllerAnalog::rightX),
                               controller.getAnalog(ControllerAnalog::rightY),
                               controller.getAnalog(ControllerAnalog::leftX));
    pros::delay(10);
  }
}
