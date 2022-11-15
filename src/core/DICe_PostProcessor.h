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

#ifndef DICE_POSTPROCESSOR_H
#define DICE_POSTPROCESSOR_H

#include <DICe.h>
#include <DICe_Mesh.h>
#include <DICe_PointCloud.h>
#include <DICe_Triangulation.h>

#include <Teuchos_ParameterList.hpp>

#include <cassert>

namespace DICe {

/// String parameter name
const char * const post_process_vsg_strain = "post_process_vsg_strain";
/// String parameter name
const char * const post_process_nlvc_strain = "post_process_nlvc_strain";
/// String Parameter name
const char * const post_process_altitude = "post_process_altitude";
/// String Parameter name
const char * const post_process_crack_locator = "post_process_crack_locator";
/// String Parameter name
const char * const crack_locator_window_size = "crack_locator_window_size";
/// String Parameter name
const char * const post_process_uncertainty = "post_process_uncertainty";
/// String parameter name
const char * const strain_window_size_in_pixels = "strain_window_size_in_pixels";
/// String Parameter name
const char * const horizon_diameter_in_pixels = "horizon_diameter_in_pixels";
/// String Parameter name
const char * const coordinates_x_field_name = "coordinates_x_field_name";
/// String Parameter name
const char * const coordinates_y_field_name = "coordinates_y_field_name";
/// String Parameter name
const char * const displacement_x_field_name = "displacement_x_field_name";
/// String Parameter name
const char * const displacement_y_field_name = "displacement_y_field_name";
/// String parameter name
const char * const post_process_live_plots = "post_process_live_plots";
/// String parameter name
const char * const post_process_plotly_contour = "post_process_plotly_contour";
/// String parameter name
const char * const plotly_contour_grid_step = "plotly_contour_grid_step";
/// String parameter name
const char * const post_process_distortion_correction = "post_process_distortion_correction";


/// Number of post processor options
const int_t num_valid_post_processor_params = 6;
/// Set of all the valid post processors
const char * const valid_post_processor_params[num_valid_post_processor_params] = {
  post_process_vsg_strain,
  post_process_nlvc_strain,
  post_process_plotly_contour,
  post_process_altitude,
  post_process_crack_locator,
  post_process_distortion_correction
};

/// String field name
const char * const altitude = "ALTITUDE";
/// String field name
const char * const vsg_strain_xx = "VSG_STRAIN_XX";
/// String field name
const char * const vsg_strain_yy = "VSG_STRAIN_YY";
/// String field name
const char * const vsg_strain_xy = "VSG_STRAIN_XY";
/// String field name
const char * const vsg_dudx = "VSG_DUDX";
/// String field name
const char * const vsg_dudy = "VSG_DUDY";
/// String field name
const char * const vsg_dvdx = "VSG_DVDX";
/// String field name
const char * const vsg_dvdy = "VSG_DVDY";
/// String field name
const char * const nlvc_strain_xx = "NLVC_STRAIN_XX";
/// String field name
const char * const nlvc_strain_yy = "NLVC_STRAIN_YY";
/// String field name
const char * const nlvc_strain_xy = "NLVC_STRAIN_XY";
/// String field name
const char * const nlvc_dudx = "NLVC_DUDX";
/// String field name
const char * const nlvc_dudy = "NLVC_DUDY";
/// String field name
const char * const nlvc_dvdx = "NLVC_DVDX";
/// String field name
const char * const nlvc_dvdy = "NLVC_DVDY";

/// \class DICe::Post_Processor
/// \brief A class for computing variables based on the field values and associated utilities
///
class DICE_LIB_DLL_EXPORT
Post_Processor{
public:
  /// \brief Default constructor
  /// \param name The name of this post processor, so that it can be referenced later or used in debugging
  Post_Processor(const std::string & name);

  /// Pure virtual destructor
  virtual ~Post_Processor(){}

  /// operations that all post processors need to do after construction
  /// \param mesh Pointer to a computational mesh with fields and discretization
  void initialize(Teuchos::RCP<DICe::mesh::Mesh> & mesh);

  /// set up the neighbor lists for each point
  /// \param neighborhood_radius inclusive radius of a point's neighborhood
  /// if the radius is positive a radius search is used to construct the neighbors
  /// if the radius is negative, the search is k-nearest neighbors with the k being (int)(-1*radius)
  void initialize_neighborhood(const scalar_t & neighborhood_radius);

  /// Tasks that are done once after initialization, but before execution
  virtual void pre_execution_tasks()=0;

  /// Returns the size of the strain window in pixels
  virtual int_t strain_window_size()=0;

  /// Read in parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params)=0;

  /// Set the field names
  void set_field_names(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Default to the model fields for post processors
  void set_stereo_field_names();

  /// update the id of the current frame
  void update_current_frame_id(const int_t frame_id){
    current_frame_id_ = frame_id;
  }

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img)=0;

  /// Return a pointer to the field spec vector
  std::vector<DICe::field_enums::Field_Spec> * field_specs(){
    return & field_specs_;
  }

protected:
  /// Pointer to the mesh to access fields and discretization
  Teuchos::RCP<DICe::mesh::Mesh> mesh_;
  /// String name of this post processor
  std::string name_;
  /// Number of points local to this processor
  int_t local_num_points_;
  /// Number of overalp points
  int_t overlap_num_points_;
  /// The collection of field names specific to this post processor
  std::vector<DICe::field_enums::Field_Spec> field_specs_;
  /// pointer to the point cloud used for the neighbor searching
  Teuchos::RCP<Point_Cloud_2D<scalar_t> > point_cloud_;
  /// array holding the number of neighbors for each point
  std::vector<std::vector<int_t> > neighbor_list_;
  /// array holding the signed x distances for each neighbor in one long strided array
  std::vector<std::vector<scalar_t> > neighbor_dist_x_;
  /// array holding the signed y distances for each neighbor in one long strided array
  std::vector<std::vector<scalar_t> > neighbor_dist_y_;
  /// true when the neighbor lists have been constructed
  bool neighborhood_initialized_;
  /// holds the field name to be used for coordinates field
  std::string coords_x_name_;
  /// holds the field name to be used for coordinates field
  std::string coords_y_name_;
  /// holds the field name to be used for coordinates field
  std::string disp_x_name_;
  /// holds the field name to be used for coordinates field
  std::string disp_y_name_;
  /// true if the fields have been customized
  bool has_custom_field_names_;
  /// store the current frame number for output if needed
  int current_frame_id_;
};

/// \class DICe::VSG_Strain_Post_Processor
/// \brief A specific instance of post processor that computes virtual strain gauge (VSG) strain
///
/// The VSG strain is computed by doing a least-squares fit of the data and computing the
/// strain using the coefficients of the fitted polynomial. It is well know that for large
/// neighborhood sizes or VSG window size, this method will be very diffusive and smooth
/// features out of the strain profile.
class DICE_LIB_DLL_EXPORT
VSG_Strain_Post_Processor : public Post_Processor {

public:

  /// Default constructor
  /// \param params Pointer to the set of parameters for this post processor
  VSG_Strain_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~VSG_Strain_Post_Processor(){}

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks();

  /// See base clase docutmentation
  virtual int_t strain_window_size(){
    return window_size_;
  }

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base class documentation
  using Post_Processor::neighborhood_initialized_;

  /// See base class documentation
  using Post_Processor::initialize_neighborhood;

  /// See base class documentation
  using Post_Processor::field_specs;

private:
  /// Window size for the virtual strain gauge (in pixels)
  int_t window_size_;
};

/// \class DICe::Distortion_Correction_Post_Processor
/// \brief A specific instance of post processor that corrects the subset displacements for image distortions
///
/// This post processor corrects the subset displacement values for lens distortions and outputs the new corrected
/// displacement field in a new field called DIST_CORRECTED_SUBSET_DISP_X and ..._Y
class DICE_LIB_DLL_EXPORT
Distortion_Correction_Post_Processor : public Post_Processor {

public:

  /// Default constructor
  /// \param params Pointer to the set of parameters for this post processor
  Distortion_Correction_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~Distortion_Correction_Post_Processor(){}

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return -1.0;}

  /// See base clase docutmentation
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params){}

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks(){};

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base class documentation
  using Post_Processor::field_specs;

protected:

  /// Triangulation to use for correcting displacements
  Teuchos::RCP<DICe::Triangulation> tri_;


};

/// \class DICe::NLVC_Strain_Post_Processor
/// \brief A specific instance of post processor that computes Nonlocal Vector Calculus (NLVC) strains
///
/// The NLVC Strain is computed by using the nonlocal correlary of the derivative operator
class DICE_LIB_DLL_EXPORT
NLVC_Strain_Post_Processor : public Post_Processor{

public:

  /// Default constructor
  /// \param params the parameters to use for this post processor
  NLVC_Strain_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~NLVC_Strain_Post_Processor(){}

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks();

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return horizon_;}

  /// compute the nonlocal kernel values
  /// \param dx distance in x,
  /// \param dy distance in y,
  /// \param kx [out] returned kernel value in x
  /// \param ky [out] returned kernel value in y
  void compute_kernel(const scalar_t & dx,
    const scalar_t & dy,
    scalar_t & kx,
    scalar_t & ky);

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base class documentation
  using Post_Processor::neighborhood_initialized_;

  /// See base class documentation
  using Post_Processor::initialize_neighborhood;

  /// See base class documentation
  using Post_Processor::field_specs;

private:
  /// Neighborhood diameter (circular distance around the point of interest where the interaction is non-negligible)
  int_t horizon_;
};

/// \class DICe::Altitude_Post_Processor
/// \brief A specific instance of post processor that computes the altitude of each subset in reference
/// to the center of the Earth. Used for satellite stereo correlation only.
class DICE_LIB_DLL_EXPORT
Altitude_Post_Processor : public Post_Processor{

public:

  /// Default constructor
  /// \param params the parameters to use for this post processor
  Altitude_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~Altitude_Post_Processor(){};

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params){}; // do nothing for this PP

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks(){}; // do nothing for this PP

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return -1.0;}

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base class documentation
  using Post_Processor::field_specs;

};


/// \class DICe::Crack_Locator_Post_Processor
/// \brief A post processor to highlight cracks using an image diff
class DICE_LIB_DLL_EXPORT
Crack_Locator_Post_Processor : public Post_Processor {

public:

  /// Default constructor
  /// \param params Pointer to the set of parameters for this post processor
  Crack_Locator_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~Crack_Locator_Post_Processor(){}

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks(){};

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return window_size_;}
private:
  /// step to use for the least squares fit
  int_t window_size_;
  /// keep a copy of the original reference image the first time execute gets called
  Teuchos::RCP<Image> ref_img_;
};


/// \class DICe::Plotly_Contour_Post_Processor
/// \brief A post processor to distill DICe output data to something Plotly could plot
/// using a contour trace, which requires regularly spaced grid and a manageable number
/// of points. The scattered dic data is interpolated using least-squares to a regular grid
class DICE_LIB_DLL_EXPORT
Plotly_Contour_Post_Processor : public Post_Processor {

public:

  /// Default constructor
  /// \param params Pointer to the set of parameters for this post processor
  Plotly_Contour_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~Plotly_Contour_Post_Processor(){}

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks(){};

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return -1.0;}

private:
  /// step to use for the regular grid
  int_t grid_step_;
};

/// \class DICe::Uncertainty_Post_Processor
/// \brief A specific instance of post processor that computes the uncertainty in the DIC displacement estimate
class DICE_LIB_DLL_EXPORT
Uncertainty_Post_Processor : public Post_Processor{

public:

  /// Default constructor
  /// \param params the parameters to use for this post processor
  Uncertainty_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~Uncertainty_Post_Processor(){};

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params){}; // do nothing for this PP

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks(){}; // do nothing for this PP

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return -1.0;}

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base class documentation
  using Post_Processor::field_specs;
};

/// \class DICe::Live_Plot_Post_Processor
/// \brief A specific instance of post processor that computes values of key quantities at specified points
class DICE_LIB_DLL_EXPORT
Live_Plot_Post_Processor : public Post_Processor{

public:

  /// Default constructor
  /// \param params the parameters to use for this post processor
  Live_Plot_Post_Processor(const Teuchos::RCP<Teuchos::ParameterList> & params);

  /// Virtual destructor
  virtual ~Live_Plot_Post_Processor(){};

  /// Set the parameters for this post processor
  virtual void set_params(const Teuchos::RCP<Teuchos::ParameterList> & params){};

  /// Collect the neighborhoods of each of the points
  virtual void pre_execution_tasks();

  /// See base clase docutmentation
  virtual int_t strain_window_size(){return -1.0;}

  /// Execute the post processor
  virtual void execute(Teuchos::RCP<Image> ref_img, Teuchos::RCP<Image> def_img);

  /// See base class documentation
  using Post_Processor::field_specs;

private:
  // number of neighbors to use in interpolating the values
  int_t num_neigh_;
  // number of individual points
  int_t num_individual_pts_;
  // number of fields in the output
  int_t num_field_entries_;
  // vector of x-coordinates for points
  std::vector<scalar_t> pts_x_;
  // vector of y-coordinates for points
  std::vector<scalar_t> pts_y_;
  // vector of the indices that this processor owns
  std::vector<int_t> local_indices_;
  // map with all fields for all points on processor 0
  Teuchos::RCP<MultiField_Map> zero_map_;
  // corresponding field for proc zero
  Teuchos::RCP<MultiField> zero_data_;
  // distributed 1 to 1 map with all points on processor with the closest node to the point
  Teuchos::RCP<MultiField_Map> dist_map_;
  // corresponding field for dist procs
  Teuchos::RCP<MultiField> dist_data_;
};


}// End DICe Namespace

#endif
