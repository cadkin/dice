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

#ifndef DICE_FIELDENUMS_H_
#define DICE_FIELDENUMS_H_

#include <DICe.h>

#include <stdlib.h>
#include <string>
#include <iostream>
#include <list>
#include <vector>

namespace DICe{

/*!
 *  \namespace DICe::field_enums
 *  @{
 */
/// Field names and properties
namespace field_enums{
/// The type of field (tensor order)
enum
DICE_LIB_DLL_EXPORT
Field_Type
{
  NO_SUCH_FIELD_TYPE=0,
  SCALAR_FIELD_TYPE,
  VECTOR_FIELD_TYPE,
  MIXED_VECTOR_FIELD_TYPE
};
/// The names of the fields
enum
DICE_LIB_DLL_EXPORT
Field_Name
{
  NO_SUCH_FIELD_NAME=0,
  INITIAL_COORDINATES,
  MODEL_COORDINATES_X,
  MODEL_COORDINATES_Y,
  MODEL_COORDINATES_Z,
  SUBSET_COORDINATES_X,
  SUBSET_COORDINATES_Y,
  STEREO_COORDINATES_X,
  STEREO_COORDINATES_Y,
  CROSS_CORR_Q,
  CROSS_CORR_R,
  INITIAL_CELL_COORDINATES,
  INITIAL_CELL_SIZE,
  INITIAL_SUBELEMENT_SIZE,
  INITIAL_WEIGHTED_CELL_SIZE,
  INITIAL_CELL_RADIUS,
  DISPLACEMENT,
  PROJECTION_AUG_X,
  PROJECTION_AUG_Y,
  SUBSET_DISPLACEMENT_X,
  SUBSET_DISPLACEMENT_Y,
  STEREO_DISPLACEMENT_X,
  STEREO_DISPLACEMENT_Y,
  MODEL_DISPLACEMENT_X,
  MODEL_DISPLACEMENT_Y,
  MODEL_DISPLACEMENT_Z,
  ROTATION_Z,
  SIGMA,
  SSSIG,
  GAMMA,
  BETA,
  OMEGA,
  NOISE_LEVEL,
  CONTRAST_LEVEL,
  ACTIVE_PIXELS,
  MATCH,
  ITERATIONS,
  STATUS_FLAG,
  NEIGHBOR_ID,
  CONDITION_NUMBER,
  SHEAR_STRETCH_XY,
  NORMAL_STRETCH_XX,
  NORMAL_STRETCH_YY,
  LAGRANGE_MULTIPLIER,
  RESIDUAL,
  GLOBAL_GRAY_DIFF,
  MIXED_RESIDUAL,
  LHS,
  MIXED_LHS,
  EXACT_SOL_VECTOR,
  EXACT_LAGRANGE_MULTIPLIER,
  IMAGE_PHI,
  IMAGE_GRAD_PHI,
  INTERNAL_FACE_EDGE_NORMAL,
  INTERNAL_FACE_EDGE_COORDINATES,
  INTERNAL_FACE_EDGE_SIZE,
  EXTERNAL_FACE_EDGE_NORMAL,
  EXTERNAL_FACE_EDGE_COORDINATES,
  EXTERNAL_FACE_EDGE_SIZE,
  INTERNAL_CELL_COORDINATES,
  INTERNAL_CELL_SIZE,
  BLOCK_ID,
  PROCESSOR_ID,
  MASTER_NODE_ID,
  QUAD_A,
  QUAD_B,
  QUAD_C,
  QUAD_D,
  QUAD_E,
  QUAD_F,
  QUAD_G,
  QUAD_H,
  QUAD_I,
  QUAD_J,
  QUAD_K,
  QUAD_L,
  EPI_A,
  EPI_B,
  EPI_C,
  CROSS_EPI_ERROR,
  FIELD_1,
  FIELD_2,
  FIELD_3,
  FIELD_4,
  FIELD_5,
  FIELD_6,
  FIELD_7,
  FIELD_8,
  FIELD_9,
  FIELD_10,
  U_X_DERIV,
  U_Y_DERIV,
  V_X_DERIV,
  V_Y_DERIV,
  DU_DX_EXACT,
  DU_DY_EXACT,
  DV_DX_EXACT,
  DV_DY_EXACT,
  STRAIN_CONTRIBS,
  GREEN_LAGRANGE_STRAIN_XX,
  GREEN_LAGRANGE_STRAIN_YY,
  GREEN_LAGRANGE_STRAIN_XY,
  EXACT_STRAIN_XX,
  EXACT_STRAIN_YY,
  EXACT_STRAIN_XY,
  VSG_STRAIN_XX,
  VSG_STRAIN_YY,
  VSG_STRAIN_XY,
  VSG_DUDX,
  VSG_DUDY,
  VSG_DVDX,
  VSG_DVDY,
  NLVC_STRAIN_XX,
  NLVC_STRAIN_YY,
  NLVC_STRAIN_XY,
  NLVC_DUDX,
  NLVC_DUDY,
  NLVC_DVDX,
  NLVC_DVDY,
  EARTH_SURFACE_X,
  EARTH_SURFACE_Y,
  EARTH_SURFACE_Z,
  ALTITUDE,
  ALTITUDE_ABOVE_GROUND,
  ACCUMULATED_DISP,
  DISP_ERROR,
  VSG_STRAIN_XX_ERROR,
  VSG_STRAIN_XY_ERROR,
  VSG_STRAIN_YY_ERROR,
  NLVC_STRAIN_XX_ERROR,
  NLVC_STRAIN_XY_ERROR,
  NLVC_STRAIN_YY_ERROR,
  UNCERTAINTY,
  UNCERTAINTY_ANGLE,
  STEREO_M_MAX,
	PROJECTION_Z,
	PROJECTION_PHI,
	PROJECTION_THETA,
  ROT_TRANS_3D_ANG_X,
  ROT_TRANS_3D_ANG_Y,
  ROT_TRANS_3D_ANG_Z,
  ROT_TRANS_3D_TRANS_X,
  ROT_TRANS_3D_TRANS_Y,
  ROT_TRANS_3D_TRANS_Z
};
/// The location that the fields live
enum
DICE_LIB_DLL_EXPORT
Entity_Rank
{
  NO_SUCH_ENTITY_RANK=0,
  NODE_RANK,
  ELEMENT_RANK,
  SUBELEMENT_RANK,
  FACE_RANK,
  EDGE_RANK,
  INTERNAL_FACE_EDGE_RANK,
  EXTERNAL_FACE_EDGE_RANK,
  INTERNAL_CELL_RANK,
  BOND_RANK
};
/// The state of the fields
enum
DICE_LIB_DLL_EXPORT
Field_State
{
  NO_FIELD_STATE=0,
  STATE_N_MINUS_ONE,
  STATE_N,
  STATE_N_PLUS_ONE
};
}  //field enums
/// converts a field name to short string
/// \param field_name the field type
DICE_LIB_DLL_EXPORT
std::string tostring_short(const field_enums::Field_Name & field_name);
/// converts a field type to string
/// \param field_type the field type
DICE_LIB_DLL_EXPORT
std::string tostring(const field_enums::Field_Type & field_type);
/// converts a field name to a string
/// \param field_name the field name
DICE_LIB_DLL_EXPORT
std::string tostring(const field_enums::Field_Name & field_name);
/// converts a field rank to string
/// \param field_rank the field rank
DICE_LIB_DLL_EXPORT
std::string tostring(const field_enums::Entity_Rank & field_rank);
/// converts a string to a field type
/// \param input_string the input string
DICE_LIB_DLL_EXPORT
field_enums::Field_Type string_to_field_type(const std::string & input_string);
/// converts a string to a field name
/// \param input_string the input string
DICE_LIB_DLL_EXPORT
field_enums::Field_Name string_to_field_name(const std::string & input_string);
/// updates the field names by adding the given field to the list
/// \param field_name the name of the field to add
/// \param input_string the string name of the field
DICE_LIB_DLL_EXPORT
void update_field_names(const field_enums::Field_Name & field_name,
  const std::string & input_string);

/// returns the number of field names
DICE_LIB_DLL_EXPORT
int_t num_field_names();
/// returns a list of the fields in reverse order
DICE_LIB_DLL_EXPORT
std::list<std::string> get_reverse_sorted_field_names();
/// converts a string to entity rank
/// \param input_string the input string
DICE_LIB_DLL_EXPORT
field_enums::Entity_Rank string_to_entity_rank(const std::string & input_string);

namespace field_enums{
/// A struct that holds all the necessary information to define a field
struct
DICE_LIB_DLL_EXPORT
Field_Spec  {
private:
  /// field type
  Field_Type field_type_;
  /// field name
  Field_Name name_;
  /// field rank
  Entity_Rank rank_;
  /// field state
  Field_State state_;
  /// True if this field can be printed or output to exodus file
  bool is_printable_;
  /// True if this field is a degree of freedom for a particular physics
  bool is_dof_;
public:
  /// Constructor
  /// \param field_type The type of field
  /// \param label The name of the field
  /// \param rank The rank of the field
  /// \param field_state The state for this field
  /// \param is_printable True if this field can be output in the exodus mesh
  /// \param is_dof True if this field is a degree of freedon
  Field_Spec(const Field_Type field_type,
    const Field_Name label,
    const Entity_Rank rank,
    const Field_State field_state,
    const bool is_printable,
    const bool is_dof=false);

  /// Constructor with no arguments
  Field_Spec();

  /// Comparison operator
  /// \param right The field spec to compare to
  bool operator == (const Field_Spec& right) const;

  /// Comparison operator
  /// \param right The field spec to compare to
  bool operator != (const Field_Spec& right) const;

  /// Comparison operator
  /// \param right The field spec to compare to
  bool operator< (const Field_Spec & right) const
  {
    if( name_ == right.get_name())
      return state_ < right.get_state();
    else
      return name_ < right.get_name();
  }

  /// Print the field to the given os
  /// \param os The output stream
  std::ostream& print(std::ostream& os) const;

  /// Return the field type
  Field_Type get_field_type() const {
    return field_type_;
  }

  /// Return the field name
  Field_Name get_name() const {
    return name_;
  }

  /// Return the field state
  Field_State get_state() const {
    return state_;
  }

  /// Set the field's state
  void set_state(Field_State state) {
    state_ = state;
  }

  /// Return the name of the field as a string
  std::string get_name_label() const {
    return tostring(name_);
  }

  /// Return the rank of the field
  Entity_Rank get_rank() const {
    return rank_;
  }

  /// Returns true if the field is printable
  bool is_printable() const {
    return is_printable_;
  }

  /// Returns true if this field is a degree of freedom for a physics class
  bool is_dof() const {
    return is_dof_;
  }

  /// True if the two fields are compatible
  /// \param field_spec The field_spec to compare to
  bool is_compatible(const Field_Spec & field_spec)const{
    return (field_spec.get_field_type()==field_type_&&field_spec.get_rank()==rank_);
  }

  /// Returns true if the field can be a subrank of the given rank (for example internal faces or edges)
  bool is_subrank_of(const field_enums::Entity_Rank parent_rank)
  {
    if(rank_!=field_enums::INTERNAL_FACE_EDGE_RANK && rank_!=field_enums::INTERNAL_CELL_RANK && rank_!= EXTERNAL_FACE_EDGE_RANK) return false;
    if(parent_rank==field_enums::ELEMENT_RANK) return true;
    else return false;
  }
};

/// stream print operator for a field spec
/// \param os the out stream
/// \param fs the field spec
DICE_LIB_DLL_EXPORT
inline std::ostream& operator<<(std::ostream& os,
  const Field_Spec& fs) {
    return fs.print(os);
}

// TODO remove some of these unneccsary field names

/// field spec
const Field_Spec NO_SUCH_FS(field_enums::NO_SUCH_FIELD_TYPE,field_enums::NO_SUCH_FIELD_NAME,field_enums::NO_SUCH_ENTITY_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec PROCESSOR_ID_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::PROCESSOR_ID,field_enums::ELEMENT_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec MASTER_NODE_ID_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MASTER_NODE_ID,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec BLOCK_ID_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::BLOCK_ID,field_enums::ELEMENT_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec INITIAL_COORDINATES_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::INITIAL_COORDINATES,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec SUBSET_COORDINATES_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SUBSET_COORDINATES_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec SUBSET_COORDINATES_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SUBSET_COORDINATES_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec STEREO_COORDINATES_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STEREO_COORDINATES_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec STEREO_COORDINATES_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STEREO_COORDINATES_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec MODEL_COORDINATES_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MODEL_COORDINATES_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec MODEL_COORDINATES_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MODEL_COORDINATES_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec MODEL_COORDINATES_Z_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MODEL_COORDINATES_Z,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec INITIAL_CELL_COORDINATES_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::INITIAL_CELL_COORDINATES,field_enums::ELEMENT_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec INITIAL_CELL_SIZE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::INITIAL_CELL_SIZE,field_enums::ELEMENT_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec INITIAL_SUBELEMENT_SIZE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::INITIAL_SUBELEMENT_SIZE,field_enums::SUBELEMENT_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec INITIAL_WEIGHTED_CELL_SIZE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::INITIAL_WEIGHTED_CELL_SIZE,field_enums::ELEMENT_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec INITIAL_CELL_RADIUS_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::INITIAL_CELL_RADIUS,field_enums::ELEMENT_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec INTERNAL_FACE_EDGE_NORMAL_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::INTERNAL_FACE_EDGE_NORMAL,field_enums::INTERNAL_FACE_EDGE_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec INTERNAL_FACE_EDGE_COORDINATES_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::INTERNAL_FACE_EDGE_COORDINATES,field_enums::INTERNAL_FACE_EDGE_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec INTERNAL_FACE_EDGE_SIZE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::INTERNAL_FACE_EDGE_SIZE,field_enums::INTERNAL_FACE_EDGE_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec INTERNAL_CELL_COORDINATES_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::INTERNAL_CELL_COORDINATES,field_enums::INTERNAL_CELL_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec INTERNAL_CELL_SIZE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::INTERNAL_CELL_SIZE,field_enums::INTERNAL_CELL_RANK,field_enums::NO_FIELD_STATE,false);
/// field spec
const Field_Spec DISPLACEMENT_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::DISPLACEMENT,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec DISPLACEMENT_NM1_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::DISPLACEMENT,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec CROSS_CORR_Q_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::CROSS_CORR_Q,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec CROSS_CORR_R_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::CROSS_CORR_R,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec PROJECTION_AUG_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::PROJECTION_AUG_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec PROJECTION_AUG_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::PROJECTION_AUG_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec SUBSET_DISPLACEMENT_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SUBSET_DISPLACEMENT_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec SUBSET_DISPLACEMENT_X_NM1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SUBSET_DISPLACEMENT_X,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec SUBSET_DISPLACEMENT_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SUBSET_DISPLACEMENT_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec SUBSET_DISPLACEMENT_Y_NM1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SUBSET_DISPLACEMENT_Y,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec STEREO_SUBSET_DISPLACEMENT_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STEREO_DISPLACEMENT_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec STEREO_SUBSET_DISPLACEMENT_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STEREO_DISPLACEMENT_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec MODEL_DISPLACEMENT_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MODEL_DISPLACEMENT_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec MODEL_DISPLACEMENT_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MODEL_DISPLACEMENT_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec MODEL_DISPLACEMENT_Z_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MODEL_DISPLACEMENT_Z,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec ROTATION_Z_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::ROTATION_Z,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,true);
/// field spec
const Field_Spec ROTATION_Z_NM1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::ROTATION_Z,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec RESIDUAL_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::RESIDUAL,field_enums::NODE_RANK,field_enums::STATE_N_PLUS_ONE,true,true);
/// field spec
const Field_Spec GLOBAL_GRAY_DIFF_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::GLOBAL_GRAY_DIFF,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true,false);
/// field spec
const Field_Spec LHS_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::LHS,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec LAGRANGE_MULTIPLIER_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::LAGRANGE_MULTIPLIER,field_enums::NODE_RANK,field_enums::STATE_N_PLUS_ONE,true,true);
/// field spec
const Field_Spec MIXED_RESIDUAL_FS(field_enums::MIXED_VECTOR_FIELD_TYPE,field_enums::MIXED_RESIDUAL,field_enums::NODE_RANK,field_enums::STATE_N_PLUS_ONE,true,true);
/// field spec
const Field_Spec MIXED_LHS_FS(field_enums::MIXED_VECTOR_FIELD_TYPE,field_enums::MIXED_LHS,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec IMAGE_PHI_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::IMAGE_PHI,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec IMAGE_GRAD_PHI_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::IMAGE_GRAD_PHI,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EXACT_SOL_VECTOR_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::EXACT_SOL_VECTOR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EXACT_LAGRANGE_MULTIPLIER_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EXACT_LAGRANGE_MULTIPLIER,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec SIGMA_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SIGMA,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec SSSIG_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SSSIG,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec GAMMA_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::GAMMA,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec BETA_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::BETA,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec OMEGA_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::OMEGA,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NOISE_LEVEL_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NOISE_LEVEL,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec CONTRAST_LEVEL_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::CONTRAST_LEVEL,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec ACTIVE_PIXELS_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::ACTIVE_PIXELS,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec MATCH_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::MATCH,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec ITERATIONS_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::ITERATIONS,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec STATUS_FLAG_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STATUS_FLAG,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NEIGHBOR_ID_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NEIGHBOR_ID,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec CONDITION_NUMBER_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::CONDITION_NUMBER,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec SHEAR_STRETCH_XY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SHEAR_STRETCH_XY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec SHEAR_STRETCH_XY_NM1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::SHEAR_STRETCH_XY,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec NORMAL_STRETCH_XX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NORMAL_STRETCH_XX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NORMAL_STRETCH_XX_NM1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NORMAL_STRETCH_XX,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec NORMAL_STRETCH_YY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NORMAL_STRETCH_YY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NORMAL_STRETCH_YY_NM1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NORMAL_STRETCH_YY,field_enums::NODE_RANK,field_enums::STATE_N_MINUS_ONE,false,true);
/// field spec
const Field_Spec QUAD_A_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_A,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_B_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_B,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_C_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_C,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_D_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_D,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_E_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_E,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_F_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_F,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_G_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_G,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_H_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_H,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_I_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_I,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_J_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_J,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_K_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_K,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec QUAD_L_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::QUAD_L,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EPI_A_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EPI_A,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EPI_B_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EPI_B,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EPI_C_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EPI_C,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec CROSS_EPI_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::CROSS_EPI_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_1_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_1,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_2_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_2,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_3_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_3,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_4_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_4,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_5_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_5,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_6_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_6,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_7_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_7,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_8_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_8,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_9_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_9,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec FIELD_10_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::FIELD_10,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DU_DX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::U_X_DERIV,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DU_DY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::U_Y_DERIV,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DV_DX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::V_X_DERIV,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DV_DY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::V_Y_DERIV,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DU_DX_EXACT_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::DU_DX_EXACT,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DU_DY_EXACT_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::DU_DY_EXACT,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DV_DX_EXACT_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::DV_DX_EXACT,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DV_DY_EXACT_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::DV_DY_EXACT,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec STRAIN_CONTRIBS_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STRAIN_CONTRIBS,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec GREEN_LAGRANGE_STRAIN_XX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::GREEN_LAGRANGE_STRAIN_XX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec GREEN_LAGRANGE_STRAIN_YY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::GREEN_LAGRANGE_STRAIN_YY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec GREEN_LAGRANGE_STRAIN_XY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::GREEN_LAGRANGE_STRAIN_XY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_STRAIN_XX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_STRAIN_XX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_STRAIN_YY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_STRAIN_YY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_STRAIN_XY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_STRAIN_XY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_DUDX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_DUDX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_DUDY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_DUDY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_DVDX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_DVDX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_DVDY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_DVDY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec STEREO_M_MAX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::STEREO_M_MAX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec UNCERTAINTY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::UNCERTAINTY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec UNCERTAINTY_ANGLE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::UNCERTAINTY_ANGLE,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EARTH_SURFACE_X_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EARTH_SURFACE_X,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EARTH_SURFACE_Y_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EARTH_SURFACE_Y,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EARTH_SURFACE_Z_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EARTH_SURFACE_Z,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec ALTITUDE_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::ALTITUDE,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec ALTITUDE_ABOVE_GROUND_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::ALTITUDE_ABOVE_GROUND,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_STRAIN_XX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_STRAIN_XX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_STRAIN_YY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_STRAIN_YY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_STRAIN_XY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_STRAIN_XY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_DUDX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_DUDX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_DUDY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_DUDY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_DVDX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_DVDX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_DVDY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_DVDY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EXACT_STRAIN_XX_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EXACT_STRAIN_XX,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EXACT_STRAIN_YY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EXACT_STRAIN_YY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec EXACT_STRAIN_XY_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::EXACT_STRAIN_XY,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec ACCUMULATED_DISP_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::ACCUMULATED_DISP,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec DISP_ERROR_FS(field_enums::VECTOR_FIELD_TYPE,field_enums::DISP_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_STRAIN_XX_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_STRAIN_XX_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_STRAIN_XY_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_STRAIN_XY_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec VSG_STRAIN_YY_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::VSG_STRAIN_YY_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_STRAIN_XX_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_STRAIN_XX_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_STRAIN_XY_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_STRAIN_XY_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec NLVC_STRAIN_YY_ERROR_FS(field_enums::SCALAR_FIELD_TYPE,field_enums::NLVC_STRAIN_YY_ERROR,field_enums::NODE_RANK,field_enums::NO_FIELD_STATE,true);
/// field spec
const Field_Spec PROJECTION_Z_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::PROJECTION_Z, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec PROJECTION_PHI_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::PROJECTION_PHI, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec PROJECTION_THETA_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::PROJECTION_THETA, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec ROT_TRANS_3D_ANG_X_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::ROT_TRANS_3D_ANG_X, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec ROT_TRANS_3D_ANG_Y_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::ROT_TRANS_3D_ANG_Y, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec ROT_TRANS_3D_ANG_Z_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::ROT_TRANS_3D_ANG_Z, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec ROT_TRANS_3D_TRANS_X_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::ROT_TRANS_3D_TRANS_X, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec ROT_TRANS_3D_TRANS_Y_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::ROT_TRANS_3D_TRANS_Y, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);
/// field spec
const Field_Spec ROT_TRANS_3D_TRANS_Z_FS(field_enums::SCALAR_FIELD_TYPE, field_enums::ROT_TRANS_3D_TRANS_Z, field_enums::NODE_RANK, field_enums::NO_FIELD_STATE, true);

/// the number of fields that have been defined (must be set at compile time)
const int_t num_fields_defined = 142;

/// array of all the valid field specs
const field_enums::Field_Spec fs_spec_vec[num_fields_defined] = {
    NO_SUCH_FS,
    INITIAL_COORDINATES_FS,
    SUBSET_COORDINATES_X_FS,
    SUBSET_COORDINATES_Y_FS,
    STEREO_COORDINATES_X_FS,
    STEREO_COORDINATES_Y_FS,
    MODEL_COORDINATES_X_FS,
    MODEL_COORDINATES_Y_FS,
    MODEL_COORDINATES_Z_FS,
    INITIAL_CELL_COORDINATES_FS,
    INITIAL_CELL_SIZE_FS,
    INITIAL_SUBELEMENT_SIZE_FS,
    INITIAL_WEIGHTED_CELL_SIZE_FS,
    INITIAL_CELL_RADIUS_FS,
    DISPLACEMENT_FS,
    CROSS_CORR_Q_FS,
    CROSS_CORR_R_FS,
    PROJECTION_AUG_X_FS,
    PROJECTION_AUG_Y_FS,
    SUBSET_DISPLACEMENT_X_FS,
    SUBSET_DISPLACEMENT_X_NM1_FS,
    SUBSET_DISPLACEMENT_Y_FS,
    SUBSET_DISPLACEMENT_Y_NM1_FS,
    STEREO_SUBSET_DISPLACEMENT_X_FS,
    STEREO_SUBSET_DISPLACEMENT_Y_FS,
    MODEL_DISPLACEMENT_X_FS,
    MODEL_DISPLACEMENT_Y_FS,
    MODEL_DISPLACEMENT_Z_FS,
    ROTATION_Z_FS,
    ROTATION_Z_NM1_FS,
    RESIDUAL_FS,
    SIGMA_FS,
    SSSIG_FS,
    GAMMA_FS,
    BETA_FS,
    OMEGA_FS,
    NOISE_LEVEL_FS,
    CONTRAST_LEVEL_FS,
    ACTIVE_PIXELS_FS,
    MATCH_FS,
    ITERATIONS_FS,
    STATUS_FLAG_FS,
    NEIGHBOR_ID_FS,
    CONDITION_NUMBER_FS,
    SHEAR_STRETCH_XY_FS,
    NORMAL_STRETCH_XX_FS,
    NORMAL_STRETCH_YY_FS,
    SHEAR_STRETCH_XY_NM1_FS,
    NORMAL_STRETCH_XX_NM1_FS,
    NORMAL_STRETCH_YY_NM1_FS,
    LHS_FS,
    LAGRANGE_MULTIPLIER_FS,
    MIXED_RESIDUAL_FS,
    MIXED_LHS_FS,
    EXACT_SOL_VECTOR_FS,
    EXACT_LAGRANGE_MULTIPLIER_FS,
    IMAGE_PHI_FS,
    IMAGE_GRAD_PHI_FS,
    INTERNAL_FACE_EDGE_NORMAL_FS,
    INTERNAL_FACE_EDGE_COORDINATES_FS,
    INTERNAL_FACE_EDGE_SIZE_FS,
    INTERNAL_CELL_COORDINATES_FS,
    INTERNAL_CELL_SIZE_FS,
    BLOCK_ID_FS,
    PROCESSOR_ID_FS,
    MASTER_NODE_ID_FS,
    QUAD_A_FS,
    QUAD_B_FS,
    QUAD_C_FS,
    QUAD_D_FS,
    QUAD_E_FS,
    QUAD_F_FS,
    QUAD_G_FS,
    QUAD_H_FS,
    QUAD_I_FS,
    QUAD_J_FS,
    QUAD_K_FS,
    QUAD_L_FS,
    EPI_A_FS,
    EPI_B_FS,
    EPI_C_FS,
    CROSS_EPI_ERROR_FS,
    FIELD_1_FS,
    FIELD_2_FS,
    FIELD_3_FS,
    FIELD_4_FS,
    FIELD_5_FS,
    FIELD_6_FS,
    FIELD_7_FS,
    FIELD_8_FS,
    FIELD_9_FS,
    FIELD_10_FS,
    DU_DX_FS,
    DU_DY_FS,
    DV_DX_FS,
    DV_DY_FS,
    STRAIN_CONTRIBS_FS,
    GREEN_LAGRANGE_STRAIN_XX_FS,
    GREEN_LAGRANGE_STRAIN_YY_FS,
    GREEN_LAGRANGE_STRAIN_XY_FS,
    VSG_STRAIN_XX_FS,
    VSG_STRAIN_YY_FS,
    VSG_STRAIN_XY_FS,
    VSG_DUDX_FS,
    VSG_DUDY_FS,
    VSG_DVDX_FS,
    VSG_DVDY_FS,
    EARTH_SURFACE_X_FS,
    EARTH_SURFACE_Y_FS,
    EARTH_SURFACE_Z_FS,
    ALTITUDE_FS,
    ALTITUDE_ABOVE_GROUND_FS,
    UNCERTAINTY_FS,
    UNCERTAINTY_ANGLE_FS,
    STEREO_M_MAX_FS,
    NLVC_STRAIN_XX_FS,
    NLVC_STRAIN_YY_FS,
    NLVC_STRAIN_XY_FS,
    NLVC_DUDX_FS,
    NLVC_DUDY_FS,
    NLVC_DVDX_FS,
    NLVC_DVDY_FS,
    EXACT_STRAIN_XX_FS,
    EXACT_STRAIN_YY_FS,
    EXACT_STRAIN_XY_FS,
    ACCUMULATED_DISP_FS,
    DISP_ERROR_FS,
    VSG_STRAIN_XX_ERROR_FS,
    VSG_STRAIN_XY_ERROR_FS,
    VSG_STRAIN_YY_ERROR_FS,
    NLVC_STRAIN_XX_ERROR_FS,
    NLVC_STRAIN_XY_ERROR_FS,
    NLVC_STRAIN_YY_ERROR_FS,
		PROJECTION_Z_FS,
		PROJECTION_PHI_FS,
		PROJECTION_THETA_FS,
    ROT_TRANS_3D_ANG_X_FS,
    ROT_TRANS_3D_ANG_Y_FS,
    ROT_TRANS_3D_ANG_Z_FS,
    ROT_TRANS_3D_TRANS_X_FS,
    ROT_TRANS_3D_TRANS_Y_FS,
    ROT_TRANS_3D_TRANS_Z_FS
      // don't forget to add one to num_fields_defined
};

/// vector of all the field specs
const std::vector<field_enums::Field_Spec> FIELD_SPEC_VECTOR(fs_spec_vec,fs_spec_vec+num_fields_defined);
} //field enums


} // end DICe namespace

#endif /* DICE_FIELDENUMS_H_ */
