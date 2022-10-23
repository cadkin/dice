// @HEADER
// ************************************************************************
//
//               Digital Image Correlation Engine (DICe)
//                 Copyright 2021 National Technology & Engineering Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY NTESS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NTESS OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact: Dan Turner (dzturne@sandia.gov)
//
// ************************************************************************
// @HEADER

#include <DICe_ParameterUtilities.h>
#include <DICe.h>
#include <cassert>
#include <iostream>


namespace DICe {

DICE_LIB_DLL_EXPORT
void stringToUpper(std::string &s){
  std::transform(s.begin(), s.end(),s.begin(), ::toupper);
}

DICE_LIB_DLL_EXPORT
void stringToLower(std::string &s){
  std::transform(s.begin(), s.end(),s.begin(), ::tolower);
}

DICE_LIB_DLL_EXPORT
const std::string to_string(Status_Flag in){
  assert(in < MAX_STATUS_FLAG);
  const static char * statusFlagStrings[] = {
    "CORRELATION_SUCCESSFUL",
    "INITIALIZE_USING_PREVIOUS_STEP_SUCCESSFUL",
    "INITIALIZE_USING_CONNECTED_SUBSET_VALUE_SUCCESSFUL",
    "INITIALIZE_USING_NEIGHBOR_VALUE_SUCCESSFUL",
    "INITIALIZE_SUCCESSFUL",
    "INITIALIZE_FAILED",
    "SEARCH_SUCCESSFUL",
    "SEARCH_FAILED",
    "CORRELATION_FAILED",
    "SUBSET_CONSTRUCTION_FAILED",
    "LINEAR_SOLVE_FAILED",
    "MAX_ITERATIONS_REACHED",
    "INITIALIZE_FAILED_BY_EXCEPTION",
    "SEARCH_FAILED_BY_EXCEPTION",
    "CORRELATION_FAILED_BY_EXCEPTION",
    "CORRELATION"
    "_BY_AVERAGING_CONNECTED_VALUES",
    "JUMP_TOLERANCE_EXCEEDED",
    "ZERO_HESSIAN_DETERMINANT",
    "SEARCH_USING_PREVIOUS_STEP_SUCCESSFUL",
    "LINEARIZED_GAMMA_OUT_OF_BOUNDS",
    "NAN_IN_HESSIAN_OR_RESIDUAL",
    "HESSIAN_SINGULAR",
    "SKIPPED_FRAME_DUE_TO_HIGH_GAMMA",
    "FRAME_FAILED_DUE_TO_HIGH_GAMMA",
    "FRAME_FAILED_DUE_TO_NEGATIVE_SIGMA",
    "FRAME_FAILED_DUE_TO_HIGH_PATH_DISTANCE",
    "RESET_REF_SUBSET_DUE_TO_HIGH_GAMMA",
    "MAX_GLOBAL_ITERATIONS_REACHED_IN_EVOLUTION_LOOP",
    "FAILURE_DUE_TO_TOO_MANY_RESTARTS",
    "FAILURE_DUE_TO_DEVIATION_FROM_PATH",
    "FRAME_SKIPPED",
    "FRAME_SKIPPED_DUE_TO_NO_MOTION"
  };
  return statusFlagStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Correlation_Routine in){
  assert(in < MAX_CORRELATION_ROUTINE);
  return correlationRoutineStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Projection_Method in){
  assert(in < MAX_PROJECTION_METHOD);
  return projectionMethodStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Global_Formulation in){
  assert(in < MAX_GLOBAL_FORMULATION);
  return globalFormulationStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Initialization_Method in){
  assert(in < MAX_INITIALIZATION_METHOD);
  return initializationMethodStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Optimization_Method in){
  assert(in < MAX_OPTIMIZATION_METHOD);
  return optimizationMethodStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Shape_Function_Type in){
  assert(in < MAX_SF);
  return shapeFunctionTypeStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Interpolation_Method in){
  assert(in < MAX_INTERPOLATION_METHOD);
  return interpolationMethodStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Gradient_Method in){
  assert(in < MAX_GRADIENT_METHOD);
  return gradientMethodStrings[in];
}
DICE_LIB_DLL_EXPORT
const std::string to_string(Global_EQ_Term in){
  assert(in < NO_SUCH_GLOBAL_EQ_TERM);
  const static char * eqTermStrings[] = {
    "IMAGE_TIME_FORCE",
    "IMAGE_GRAD_TENSOR",
    "DIV_SYMMETRIC_STRAIN_REGULARIZATION",
    "TIKHONOV_REGULARIZATION",
    "GRAD_LAGRANGE_MULTIPLIER",
    "DIV_VELOCITY",
    "MMS_IMAGE_GRAD_TENSOR",
    "MMS_FORCE",
    "MMS_IMAGE_TIME_FORCE",
    "MMS_GRAD_LAGRANGE_MULTIPLIER",
    "DIRICHLET_DISPLACEMENT_BC",
    "MMS_DIRICHLET_DISPLACEMENT_BC",
    "MMS_LAGRANGE_BC",
    "CORNER_BC",
    "OPTICAL_FLOW_DISPLACEMENT_BC",
    "SUBSET_DISPLACEMENT_BC",
    "SUBSET_DISPLACEMENT_IC",
    "LAGRANGE_BC",
    "CONSTANT_IC",
    "STAB_LAGRANGE",
    "NO_SUCH_GLOBAL_EQ_TERM"
  };
  return eqTermStrings[in];
};

DICE_LIB_DLL_EXPORT
const std::string to_string(Global_Solver in){
  assert(in < NO_SUCH_GLOBAL_SOLVER);
  const static char * globalSolverStrings[] = {
    "CG_SOLVER",
    "GMRES_SOLVER",
    "LSQR_SOLVER",
    "NO_SUCH_GLOBAL_SOLVER"
  };
  return globalSolverStrings[in];
};

DICE_LIB_DLL_EXPORT
Global_Solver string_to_global_solver(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<NO_SUCH_GLOBAL_SOLVER;++i){
    if(to_string(static_cast<Global_Solver>(i))==in) return static_cast<Global_Solver>(i);
  }
  std::cout << "Error: Global_Solver " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_GLOBAL_SOLVER; // prevent no return errors
}

DICE_LIB_DLL_EXPORT
Correlation_Routine string_to_correlation_routine(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_CORRELATION_ROUTINE;++i){
    if(correlationRoutineStrings[i]==in) return static_cast<Correlation_Routine>(i);
  }
  std::cout << "Error: Correlation_Routine " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_CORRELATION_ROUTINE; // prevent no return errors
}
DICE_LIB_DLL_EXPORT
Projection_Method string_to_projection_method(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_PROJECTION_METHOD;++i){
    if(projectionMethodStrings[i]==in) return static_cast<Projection_Method>(i);
  }
  std::cout << "Error: Projection_Method " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_PROJECTION_METHOD; // prevent no return errors
}
DICE_LIB_DLL_EXPORT
Global_Formulation string_to_global_formulation(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_GLOBAL_FORMULATION;++i){
    if(globalFormulationStrings[i]==in) return static_cast<Global_Formulation>(i);
  }
  std::cout << "Error: Global_Formulation " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_GLOBAL_FORMULATION; // prevent no return errors
}
DICE_LIB_DLL_EXPORT
Initialization_Method string_to_initialization_method(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_INITIALIZATION_METHOD;++i){
    if(initializationMethodStrings[i]==in) return static_cast<Initialization_Method>(i);
  }
  std::cout << "Error: Initialization_Method " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_INITIALIZATION_METHOD; // prevent no return errors
}
DICE_LIB_DLL_EXPORT
Optimization_Method string_to_optimization_method(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_OPTIMIZATION_METHOD;++i){
    if(optimizationMethodStrings[i]==in) return static_cast<Optimization_Method>(i);
  }
  std::cout << "Error: Optimization_Method " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_OPTIMIZATION_METHOD; // prevent no return errors
}
DICE_LIB_DLL_EXPORT
Interpolation_Method string_to_interpolation_method(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_INTERPOLATION_METHOD;++i){
    if(interpolationMethodStrings[i]==in) return static_cast<Interpolation_Method>(i);
  }
  std::cout << "Error: Interpolation_Method " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_INTERPOLATION_METHOD; // prevent no return errors
}

DICE_LIB_DLL_EXPORT
Gradient_Method string_to_gradient_method(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_GRADIENT_METHOD;++i){
    if(gradientMethodStrings[i]==in) return static_cast<Gradient_Method>(i);
  }
  std::cout << "Error: Gradient_Method " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_GRADIENT_METHOD; // prevent no return errors
}
DICE_LIB_DLL_EXPORT
Shape_Function_Type string_to_shape_function_type(std::string & in){
  // convert the string to uppercase
  stringToUpper(in);
  for(int_t i=0;i<MAX_SF;++i){
    if(shapeFunctionTypeStrings[i]==in) return static_cast<Shape_Function_Type>(i);
  }
  std::cout << "Error: Shape_Function_Type " << in << " does not exist." << std::endl;
  TEUCHOS_TEST_FOR_EXCEPTION(true,std::invalid_argument,"");
  return NO_SUCH_SF; // prevent no return errors
}

/// Determine if the parameter is a string parameter
DICE_LIB_DLL_EXPORT
bool is_string_param(const std::string & in){
  // change the string to lower case (string param names are lower)
  std::string lower = in;
  stringToLower(lower);
  for(int_t i=0;i<num_valid_correlation_params;++i){
    if(lower==valid_correlation_params[i].name_ && valid_correlation_params[i].type_==STRING_PARAM)
      return true;
  }
  return false;
}


DICE_LIB_DLL_EXPORT void tracking_default_params(Teuchos::ParameterList *  defaultParams){
  defaultParams->set(DICe::correlation_routine,DICe::TRACKING_ROUTINE);
  defaultParams->set(DICe::max_evolution_iterations,10);
  defaultParams->set(DICe::max_solver_iterations_fast,25);
  defaultParams->set(DICe::max_solver_iterations_robust,1000);
  defaultParams->set(DICe::robust_solver_tolerance,1.0E-6);
  defaultParams->set(DICe::fast_solver_tolerance,1.0E-4);
  defaultParams->set(DICe::robust_delta_disp,1.0);  // simplex method initial shape is based on these
  defaultParams->set(DICe::robust_delta_theta,0.1); //
  defaultParams->set(DICe::interpolation_method,DICe::KEYS_FOURTH);
  defaultParams->set(DICe::gradient_method,DICe::FINITE_DIFFERENCE);
  defaultParams->set(DICe::optimization_method,DICe::SIMPLEX);
  defaultParams->set(DICe::initialization_method,DICe::USE_FIELD_VALUES);
  defaultParams->set(DICe::cross_initialization_method,DICe::USE_PLANAR_PROJECTION);
  defaultParams->set(DICe::projection_method,DICe::DISPLACEMENT_BASED);
  defaultParams->set(DICe::disp_jump_tol,8.0);
  defaultParams->set(DICe::theta_jump_tol,0.1);
  defaultParams->set(DICe::shape_function_type,DICe::AFFINE_SF);
  defaultParams->set(DICe::enable_translation,true);
  defaultParams->set(DICe::enable_rotation,true);
  defaultParams->set(DICe::enable_normal_strain,false);
  defaultParams->set(DICe::enable_shear_strain,false);
  defaultParams->set(DICe::output_deformed_subset_images,false);
  defaultParams->set(DICe::output_deformed_subset_intensity_images,false);
  defaultParams->set(DICe::output_evolved_subset_images,false);
  defaultParams->set(DICe::use_subset_evolution,true);
  defaultParams->set(DICe::override_force_simplex,true);
  defaultParams->set(DICe::use_incremental_formulation,false);
  defaultParams->set(DICe::use_nonlinear_projection,false);
  defaultParams->set(DICe::read_full_images,false);
  defaultParams->set(DICe::sort_txt_output,false);
  defaultParams->set(DICe::write_json_output,false);
  defaultParams->set(DICe::use_search_initialization_for_failed_steps,false);
  defaultParams->set(DICe::output_beta,false);
  defaultParams->set(DICe::output_delimiter,",");
  defaultParams->set(DICe::omit_output_row_id,false);
  defaultParams->set(DICe::obstruction_skin_factor,1.8);
  defaultParams->set(DICe::normalize_gamma_with_active_pixels,false);
  defaultParams->set(DICe::levenberg_marquardt_regularization_factor,-1.0);
  defaultParams->set(DICe::momentum_factor,0.0);
  defaultParams->set(DICe::pixel_integration_order,1);
  defaultParams->set(DICe::skip_solve_gamma_threshold,1.0E-10);
  defaultParams->set(DICe::skip_all_solves,false);
  defaultParams->set(DICe::initial_gamma_threshold,-1.0);
  defaultParams->set(DICe::sssig_threshold,-1.0);
  defaultParams->set(DICe::final_gamma_threshold,-1.0);
  defaultParams->set(DICe::path_distance_threshold,-1.0);
  defaultParams->set(DICe::rotate_ref_image_90,false);
  defaultParams->set(DICe::rotate_def_image_90,false);
  defaultParams->set(DICe::rotate_ref_image_180,false);
  defaultParams->set(DICe::rotate_def_image_180,false);
  defaultParams->set(DICe::rotate_ref_image_270,false);
  defaultParams->set(DICe::rotate_def_image_270,false);
  defaultParams->set(DICe::global_formulation,HORN_SCHUNCK);
  defaultParams->set(DICe::global_regularization_alpha,1.0);
  defaultParams->set(DICe::global_stabilization_tau,-1.0);
  defaultParams->set(DICe::global_solver,CG_SOLVER);
  defaultParams->set(DICe::global_element_type,"TRI6");
  defaultParams->set(DICe::num_image_integration_points,20);
  defaultParams->set(DICe::write_exodus_output,false);
  defaultParams->set(DICe::threshold_block_size,-1);
}

DICE_LIB_DLL_EXPORT void dice_default_params(Teuchos::ParameterList *  defaultParams){
  defaultParams->set(DICe::correlation_routine,DICe::GENERIC_ROUTINE);
  defaultParams->set(DICe::max_evolution_iterations,10);
  defaultParams->set(DICe::max_solver_iterations_fast,25);
  defaultParams->set(DICe::max_solver_iterations_robust,1000);
  defaultParams->set(DICe::robust_solver_tolerance,1.0E-6);
  defaultParams->set(DICe::fast_solver_tolerance,1.0E-4);
  defaultParams->set(DICe::robust_delta_disp,1.0);  // simplex method initial shape is based on these
  defaultParams->set(DICe::robust_delta_theta,0.1); //
  defaultParams->set(DICe::interpolation_method,DICe::KEYS_FOURTH);
  defaultParams->set(DICe::gradient_method,DICe::FINITE_DIFFERENCE);
  defaultParams->set(DICe::optimization_method,DICe::GRADIENT_BASED_THEN_SIMPLEX);
  defaultParams->set(DICe::initialization_method,DICe::USE_FIELD_VALUES);
  defaultParams->set(DICe::cross_initialization_method,DICe::USE_PLANAR_PROJECTION);
  defaultParams->set(DICe::projection_method,DICe::DISPLACEMENT_BASED);
  defaultParams->set(DICe::use_incremental_formulation,false);
  defaultParams->set(DICe::use_nonlinear_projection,false);
  defaultParams->set(DICe::read_full_images,false);
  defaultParams->set(DICe::sort_txt_output,false);
  defaultParams->set(DICe::write_json_output,false);
  defaultParams->set(DICe::use_search_initialization_for_failed_steps,false);
  defaultParams->set(DICe::disp_jump_tol,10000.0);
  defaultParams->set(DICe::theta_jump_tol,100.0);
  defaultParams->set(DICe::shape_function_type,DICe::AFFINE_SF);
  defaultParams->set(DICe::enable_translation,true);
  defaultParams->set(DICe::enable_rotation,false);
  defaultParams->set(DICe::enable_normal_strain,false);
  defaultParams->set(DICe::enable_shear_strain,false);
  defaultParams->set(DICe::output_deformed_subset_images,false);
  defaultParams->set(DICe::output_deformed_subset_intensity_images,false);
  defaultParams->set(DICe::output_evolved_subset_images,false);
  defaultParams->set(DICe::use_subset_evolution,false);
  defaultParams->set(DICe::override_force_simplex,false);
  defaultParams->set(DICe::output_beta,false);
  defaultParams->set(DICe::output_delimiter," ");
  defaultParams->set(DICe::omit_output_row_id,false);
  defaultParams->set(DICe::obstruction_skin_factor,1.0);
  defaultParams->set(DICe::normalize_gamma_with_active_pixels,false);
  defaultParams->set(DICe::levenberg_marquardt_regularization_factor,-1.0);
  defaultParams->set(DICe::momentum_factor,0.0);
  defaultParams->set(DICe::pixel_integration_order,1);
  defaultParams->set(DICe::skip_solve_gamma_threshold,1.0E-10);
  defaultParams->set(DICe::skip_all_solves,false);
  defaultParams->set(DICe::initial_gamma_threshold,-1.0);
  defaultParams->set(DICe::sssig_threshold,-1.0);
  defaultParams->set(DICe::final_gamma_threshold,-1.0);
  defaultParams->set(DICe::path_distance_threshold,-1.0);
  defaultParams->set(DICe::rotate_ref_image_90,false);
  defaultParams->set(DICe::rotate_def_image_90,false);
  defaultParams->set(DICe::rotate_ref_image_180,false);
  defaultParams->set(DICe::rotate_def_image_180,false);
  defaultParams->set(DICe::rotate_ref_image_270,false);
  defaultParams->set(DICe::rotate_def_image_270,false);
  defaultParams->set(DICe::global_formulation,HORN_SCHUNCK);
  defaultParams->set(DICe::global_regularization_alpha,1.0);
  defaultParams->set(DICe::global_stabilization_tau,-1.0);
  defaultParams->set(DICe::global_element_type,"TRI6");
  defaultParams->set(DICe::global_solver,CG_SOLVER);
  defaultParams->set(DICe::num_image_integration_points,20);
  defaultParams->set(DICe::write_exodus_output,true);
  defaultParams->set(DICe::threshold_block_size,-1);
}

}// End DICe Namespace
