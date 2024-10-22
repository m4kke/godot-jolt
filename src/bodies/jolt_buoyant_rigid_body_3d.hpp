#pragma once

class JoltBuoyantRigidBody3D final : public RigidBody3D {
  GDCLASS_NO_WARN(JoltBuoyantRigidBody3D, RigidBody3D)

public:
  void set_liquid_plane(const Plane& p_plane);
  const Plane& get_liquid_plane() const;

  void set_buoyancy(float p_buoyancy);
  float get_buoyancy() const;

  void set_linear_drag(float p_linear_drag);
  float get_linear_drag() const;

  void set_angular_drag(float p_angular_drag);
  float get_angular_drag() const;

    void set_slide_angle_threshold(float p_slide_angle_threshold);
  float get_slide_angle_threshold() const;
  void _integrate_forces(PhysicsDirectBodyState3D* p_body_state);

  JoltBuoyantRigidBody3D();

private:
  static void _bind_methods();

  Plane liquid_plane;
  float buoyancy = 1.0;
  float linear_drag = 0.0;
  float angular_drag = 0.0;
  float slide_angle_threshold = 2.0f * JPH::JPH_PI;
};

