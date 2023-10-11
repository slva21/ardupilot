#include "Copter.h"


ModeTest::ModeTest(void) {
    // Constructor logic, initialize variables, etc.
}

bool ModeTest::init(bool ignore_checks) {
    if (!ignore_checks) {
        // Perform pre-flight checks or initialization logic.
        // Return false if the mode should not be entered.
    }
    // Additional initialization logic.
    return true;  // Return true if mode initialization is successful.
}

void ModeTest::run() {

    // Im lets say for this interview we just want to land the drone
    
    // Check the current altitude
    float current_altitude = inertial_nav.get_position_z_up_cm() / 100.0f; // Convert to meters

    float target_alt = 0.0f;

    // If we are not on the ground yet, command descent
    if (current_altitude > target_alt) {
        // Set a target descent rate
        float descent_rate = -0.5f;  // e.g., descend at 0.5 m/s
        
        // Command descent using an appropriate control function from ArduPilot's libraries
        // This might involve setting desired velocities or attitudes that the lower-level control loops will work to achieve
        // Note: Specific function calls will depend on your vehicle type and the APIs provided by ArduPilot
        pos_control->set_velocity_z(descent_rate);
        
        // Other potential logic: managing landing gear, monitoring for a safe descent, etc.
        
    } else {
        // If we are on the ground, disengage motors (assuming proper safeties/checks are in place!)
        motors->disarm();
        
        // Perhaps switch to a different mode, or perform other end-of-landing logic
    }


}
