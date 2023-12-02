#include <godot_cpp/variant/utility_functions.hpp>

#include "jolt_buoyant_rigid_body_3d.hpp"
#include "objects/jolt_physics_direct_body_state_3d.hpp"

JoltBuoyantRigidBody3D::JoltBuoyantRigidBody3D() : RigidBody3D() {
  set_liquid_plane(Plane(0, 1, 0, 0));
}

void JoltBuoyantRigidBody3D::_bind_methods() {
  BIND_METHOD(JoltBuoyantRigidBody3D, get_liquid_plane);
  BIND_METHOD(JoltBuoyantRigidBody3D, set_liquid_plane, "plane");

  BIND_METHOD(JoltBuoyantRigidBody3D, get_buoyancy);
  BIND_METHOD(JoltBuoyantRigidBody3D, set_buoyancy, "buoyancy");

  BIND_METHOD(JoltBuoyantRigidBody3D, get_linear_drag);
  BIND_METHOD(JoltBuoyantRigidBody3D, set_linear_drag, "linear_drag");

  BIND_METHOD(JoltBuoyantRigidBody3D, get_angular_drag);
  BIND_METHOD(JoltBuoyantRigidBody3D, set_angular_drag, "angular_drag");

  ADD_PROPERTY(PropertyInfo(Variant::PLANE, "liquid_plane", PROPERTY_HINT_NONE, "suffix:m"), "set_liquid_plane", "get_liquid_plane");
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "buoyancy", PROPERTY_HINT_RANGE, "0.0,2.0,0.1,or_greater"), "set_buoyancy", "get_buoyancy");
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "linear_drag", PROPERTY_HINT_RANGE, "0.0,2.0,0.1,or_greater"), "set_linear_drag", "get_linear_drag");
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angular_drag", PROPERTY_HINT_RANGE, "0.0,2.0,0.1,or_greater"), "set_angular_drag", "get_angular_drag");
}

void JoltBuoyantRigidBody3D::set_liquid_plane(const Plane& p_plane) {
  liquid_plane = p_plane;
}

const Plane& JoltBuoyantRigidBody3D::get_liquid_plane() const {
  return liquid_plane;
}

void JoltBuoyantRigidBody3D::set_buoyancy(float p_buoyancy) {
  ERR_FAIL_COND(p_buoyancy < 0);
  buoyancy = p_buoyancy;
}

float JoltBuoyantRigidBody3D::get_buoyancy() const {
  return buoyancy;
}

void JoltBuoyantRigidBody3D::set_linear_drag(float p_linear_drag) {
  ERR_FAIL_COND(p_linear_drag < 0);
  linear_drag = p_linear_drag;
}

float JoltBuoyantRigidBody3D::get_linear_drag() const {
  return linear_drag;
}

void JoltBuoyantRigidBody3D::set_angular_drag(float p_angular_drag) {
  ERR_FAIL_COND(p_angular_drag < 0);
  angular_drag = p_angular_drag;
}

float JoltBuoyantRigidBody3D::get_angular_drag() const {
  return angular_drag;
}

void JoltBuoyantRigidBody3D::_integrate_forces(PhysicsDirectBodyState3D* p_state) {
  JoltPhysicsDirectBodyState3D* p_jolt_state = (JoltPhysicsDirectBodyState3D*) p_state;
  p_jolt_state->apply_buoyancy_impulse(
      get_liquid_plane().center(),
      get_liquid_plane().normal,
      get_buoyancy(), get_linear_drag(), get_angular_drag(),
      Vector3(0.0f, 0.0f, 0.0f),
      (float) p_jolt_state->get_step()
  );
}
