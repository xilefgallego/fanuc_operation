/**********************************************************************/

/* Author: Felix German Vector*/

#include <ros/ros.h>
#include <iostream>

#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

using namespace std;

//////////////////////////////////////////
shape_msgs::SolidPrimitive creerCylindre( float height, float radius){
    shape_msgs::SolidPrimitive res; 

    res.type = res.CYLINDER;
    res.dimensions.resize(2);
    res.dimensions[0] = height;
    res.dimensions[1] = radius;

    return res;
}

//////////////////////////////////////////
geometry_msgs::Pose creerSituationCylindre(float orientationw, float orientationx, float orientationy, float orientationz, float posx, float posy, float posz){
    geometry_msgs::Pose res;

    res.orientation.x = orientationx;
    res.orientation.y = orientationy;
    res.orientation.z = orientationz;
    res.orientation.w = orientationw;

    res.position.x =  posx;
    res.position.y =  posy;
    res.position.z =  posz;

    return res;
}

//////////////////////////////////////////
/*void ajouterVigne(moveit::planning_interface::PlanningSceneInterface planning_scene_interface, moveit::planning_interface::MoveGroup group){
    
}*/


//////////////////////////////////////////
int main(int argc, char **argv){
    ros::init(argc, argv, "move_group_interface_tutorial");
    ros::NodeHandle node_handle;  
    ros::AsyncSpinner spinner(1);
    spinner.start();


    /* This sleep is ONLY to allow Rviz to come up */
    sleep(10.0);

    // BEGIN_TUTORIAL
    // 
    // Setup
    // ^^^^^
    // 
    // The :move_group_interface:`MoveGroup` class can be easily 
    // setup using just the name
    // of the group you would like to control and plan for.
    moveit::planning_interface::MoveGroup group("arm");

    // We will use the :planning_scene_interface:`PlanningSceneInterface`
    // class to deal directly with the world.
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

    // (Optional) Create a publisher for visualizing plans in Rviz.
    ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    moveit_msgs::DisplayTrajectory display_trajectory;

    // Getting Basic Information
    // ^^^^^^^^^^^^^^^^^^^^^^^^^
    //
    // We can print the name of the reference frame for this robot.
    ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());

    // We can also print the name of the end-effector link for this group.
    ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());



    // Planning to a Pose goal
    // ^^^^^^^^^^^^^^^^^^^^^^^
    // We can plan a motion for this group to a desired pose for the 
    // end-effector.
    geometry_msgs::Pose target_pose1;
    target_pose1.orientation.w = 1.0;
    target_pose1.position.x = 0.28;
    target_pose1.position.y = -0.7;
    target_pose1.position.z = 1.0;
    group.setPoseTarget(target_pose1);


    // Now, we call the planner to compute the plan
    // and visualize it.
    // Note that we are just planning, not asking move_group 
    // to actually move the robot.
    moveit::planning_interface::MoveGroup::Plan my_plan;
    bool success = group.plan(my_plan);

    ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
    /* Sleep to give Rviz time to visualize the plan. */
    //sleep(3.0);


    // Planning with Path Constraints
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //
    // Path constraints can easily be specified for a link on the robot.
    // Let's specify a path constraint and a pose goal for our group.
    // First define the path constraint.
    moveit_msgs::OrientationConstraint ocm;  
    ocm.link_name = "link_6";  
    ocm.header.frame_id = "base_link";
    ocm.orientation.w = 1.0;
    ocm.absolute_x_axis_tolerance = 0.1;
    ocm.absolute_y_axis_tolerance = 0.1;
    ocm.absolute_z_axis_tolerance = 0.1;
    ocm.weight = 1.0;

    // Now, set it as the path constraint for the group.
    moveit_msgs::Constraints test_constraints;
    test_constraints.orientation_constraints.push_back(ocm);  
    group.setPathConstraints(test_constraints);

    // We will reuse the old goal that we had and plan to it.
    // Note that this will only work if the current state already 
    // satisfies the path constraints. So, we need to set the start
    // state to a new pose. 
    robot_state::RobotState start_state(*group.getCurrentState());
    geometry_msgs::Pose start_pose2;
    start_pose2.orientation.w = 1.0;
    start_pose2.position.x = 0.55;
    start_pose2.position.y = -0.05;
    start_pose2.position.z = 0.8;
    const robot_state::JointModelGroup *joint_model_group =
                  start_state.getJointModelGroup(group.getName());
    start_state.setFromIK(joint_model_group, start_pose2);
    group.setStartState(start_state);

    // Now we will plan to the earlier pose target from the new 
    // start state that we have just created.
    group.setPoseTarget(target_pose1);
    success = group.plan(my_plan);

    ROS_INFO("Visualizing plan 3 (constraints) %s",success?"":"FAILED");
    // Sleep to give Rviz time to visualize the plan. 
    //sleep(5.0);

    // When done with the path constraint be sure to clear it.
    group.clearPathConstraints();



    // Adding/Removing Objects and Attaching/Detaching Objects
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // First, we will define the collision object message.*/
    moveit_msgs::CollisionObject collision_object;
    collision_object.header.frame_id = group.getPlanningFrame();
    collision_object.operation = collision_object.APPEND;


    /* The id of the object is used to identify it. */
    collision_object.id = "cylinders";


    /* Define the cylinders to add to the world. */
    shape_msgs::SolidPrimitive pied = creerCylindre(0.6, 0.05);
    shape_msgs::SolidPrimitive branche = creerCylindre(1, 0.04);

    shape_msgs::SolidPrimitive sarment1 = creerCylindre(0.3, 0.005);
    shape_msgs::SolidPrimitive sarment2 = creerCylindre(0.3, 0.005);
    shape_msgs::SolidPrimitive sarment3 = creerCylindre(0.3, 0.005);
    shape_msgs::SolidPrimitive sarment4 = creerCylindre(0.3, 0.005);
    shape_msgs::SolidPrimitive sarment5 = creerCylindre(0.3, 0.005);
    shape_msgs::SolidPrimitive sarment6 = creerCylindre(0.3, 0.005);


    /* The poses for the cylinders (specified relative to frame_id) */
    geometry_msgs::Pose situationPied = creerSituationCylindre(1.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.3);
    geometry_msgs::Pose situationBranche = creerSituationCylindre(0.0, 0.0, 180.0, 180.0, 0.9, 0.0, 0.64);

    geometry_msgs::Pose situationSarment1 = creerSituationCylindre(1.0, -8.0, 7.0, 60.0, 0.855, 0.11, 0.812);
    geometry_msgs::Pose situationSarment2 = creerSituationCylindre(1.0, 7.0, -9.0, 60.0, 0.955, -0.13, 0.812);
    geometry_msgs::Pose situationSarment3 = creerSituationCylindre(0.0, 10.0, 3.0, 60.0, 0.955, 0.32, 0.812);
    geometry_msgs::Pose situationSarment4 = creerSituationCylindre(1.0, 6.0, -8.0, 60.0, 0.925, -0.34, 0.812);
    geometry_msgs::Pose situationSarment5 = creerSituationCylindre(1.0, -8.0, 5.0, 60.0, 0.855, 0.48, 0.812);
    geometry_msgs::Pose situationSarment6 = creerSituationCylindre(1.0, -10.0, -4.0, 60.0, 0.855, -0.47, 0.812);


    /* adding to the list of primitive */
    /* Cylinder 1*/
    collision_object.primitives.push_back(pied);
    collision_object.primitive_poses.push_back(situationPied);

    /*Cylinder 2*/
    collision_object.primitives.push_back(branche);
    collision_object.primitive_poses.push_back(situationBranche);

    /* Cylinder 3*/
    collision_object.primitives.push_back(sarment1);
    collision_object.primitive_poses.push_back(situationSarment1);

    /*Cylinder 4*/
    collision_object.primitives.push_back(sarment2);
    collision_object.primitive_poses.push_back(situationSarment2);

    /* Cylinder 3*/
    collision_object.primitives.push_back(sarment3);
    collision_object.primitive_poses.push_back(situationSarment3);

    /* Cylinder 3*/
    collision_object.primitives.push_back(sarment4);
    collision_object.primitive_poses.push_back(situationSarment4);

    /* Cylinder 3*/
    collision_object.primitives.push_back(sarment5);
    collision_object.primitive_poses.push_back(situationSarment5);

    /* Cylinder 3*/
    collision_object.primitives.push_back(sarment6);
    collision_object.primitive_poses.push_back(situationSarment6);


    std::vector<moveit_msgs::CollisionObject> collision_objects;  
    collision_objects.push_back(collision_object);  

    cout << "\n Orientation en x " << situationSarment1.orientation.x << endl;
    // Now, let's add the collision object into the world
    ROS_INFO("Add an object into the world");  
    planning_scene_interface.addCollisionObjects(collision_objects);

    /* Sleep so we have time to see the object in RViz */
    sleep(2.0);





    // Visualizing plans
    // ^^^^^^^^^^^^^^^^^
    // Now that we have a plan we can visualize it in Rviz.  This is not
    // necessary because the group.plan() call we made above did this
    // automatically.  But explicitly publishing plans is useful in cases that we
    // want to visualize a previously created plan.
    //if (1)
    /*{
    ROS_INFO("Visualizing plan 1 (again)");    
    display_trajectory.trajectory_start = my_plan.start_state_;
    display_trajectory.trajectory.push_back(my_plan.trajectory_);
    display_publisher.publish(display_trajectory);
    /* Sleep to give Rviz time to visualize the plan. 
    sleep(5.0);
    }*/

    // Moving to a pose goal
    // ^^^^^^^^^^^^^^^^^^^^^
    //
    // Moving to a pose goal is similar to the step above
    // except we now use the move() function. Note that
    // the pose goal we had set earlier is still active 
    // and so the robot will try to move to that goal. We will
    // not use that function in this tutorial since it is 
    // a blocking function and requires a controller to be active
    // and report success on execution of a trajectory.

    /* Uncomment below line when working with a real robot*/
    /* group.move() */

    // Planning to a joint-space goal 
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    //
    // Let's set a joint space goal and move towards it.  This will replace the
    // pose target we set above.
    //
    // First get the current set of joint values for the group.
    /*std::vector<double> group_variable_values;
    group.getCurrentState()->copyJointGroupPositions(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()), group_variable_values);

    // Now, let's modify one of the joints, plan to the new joint
    // space goal and visualize the plan.
    group_variable_values[0] = -1.0;  
    group.setJointValueTarget(group_variable_values);
    success = group.plan(my_plan);

    ROS_INFO("Visualizing plan 2 (joint space goal) %s",success?"":"FAILED");
    /* Sleep to give Rviz time to visualize the plan. */
    //sleep(5.0);



    // Cartesian Paths
    // ^^^^^^^^^^^^^^^
    // You can plan a cartesian path directly by specifying a list of waypoints 
    // for the end-effector to go through. Note that we are starting 
    // from the new start state above.  The initial pose (start state) does not
    // need to be added to the waypoint list.
    /*std::vector<geometry_msgs::Pose> waypoints;

    geometry_msgs::Pose target_pose3 = start_pose2;
    target_pose3.position.x += 0.2;
    target_pose3.position.z += 0.2;
    waypoints.push_back(target_pose3);  // up and out

    target_pose3.position.y -= 0.2;
    waypoints.push_back(target_pose3);  // left

    target_pose3.position.z -= 0.2;
    target_pose3.position.y += 0.2;
    target_pose3.position.x -= 0.2;
    waypoints.push_back(target_pose3);  // down and right (back to start)

    // We want the cartesian path to be interpolated at a resolution of 1 cm
    // which is why we will specify 0.01 as the max step in cartesian
    // translation.  We will specify the jump threshold as 0.0, effectively
    // disabling it.
    moveit_msgs::RobotTrajectory trajectory;
    double fraction = group.computeCartesianPath(waypoints,
                                               0.01,  // eef_step
                                               0.0,   // jump_threshold
                                               trajectory);

    ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
        fraction * 100.0);    
    // Sleep to give Rviz time to visualize the plan. 
    // sleep(15.0);




    // Planning with collision detection can be slow.  Lets set the planning time
    // to be sure the planner has enough time to plan around the box.  10 seconds
    // should be plenty.
    group.setPlanningTime(10.0);


    // Now when we plan a trajectory it will avoid the obstacle
    group.setStartState(*group.getCurrentState());
    group.setPoseTarget(target_pose1);
    success = group.plan(my_plan);

    ROS_INFO("Visualizing plan 5 (pose goal move around box) %s",
    success?"":"FAILED");
    // Sleep to give Rviz time to visualize the plan. 
    sleep(10.0);

    // Now, let's remove the collision object from the world.
    //ROS_INFO("Remove the object from the world");  
    //std::vector<std::string> object_ids;
    //object_ids.push_back(collision_object.id);  
    //planning_scene_interface.removeCollisionObjects(object_ids);
    /* Sleep to give Rviz time to show the object is no longer there. */
    //sleep(4.0);

    // END_TUTORIAL

    ros::shutdown();  
    return 0;
}


