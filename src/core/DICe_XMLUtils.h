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

#ifndef DICE_XMLUTILS_H
#define DICE_XMLUTILS_H

#include <iostream>

#include <Teuchos_ParameterList.hpp>

namespace DICe {

/// \brief Create the opening parameter syntax
/// \param file_name The name of the xml file
void initialize_xml_file(const std::string & file_name);

/// \brief Create the closing parameter syntax
/// \param file_name The name of the xml file
void finalize_xml_file(const std::string & file_name);

/// \brief Write a comment to the xml file specified
/// \param file_name The name of the xml file
/// \param comment String comment to print to file
void write_xml_comment(const std::string & file_name,
  const std::string & comment);

/// \brief Write the opening part of a ParameterList
/// \param file_name The xml file
/// \param name Name of the ParameterList
/// \param commented String comment to print to file
void write_xml_param_list_open(const std::string & file_name,
  const std::string & name,
  const bool commented=true);

/// \brief Write the closing part of a ParameterList
/// \param file_name The xml file
/// \param commented String comment to print to file
void write_xml_param_list_close(const std::string & file_name,
  const bool commented=true);

/// \brief Write a general xml parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param type The type of the parameter (bool, int, double, string)
/// \param value The string value of the parameter
/// \param commented Determines if this parameter should be commented out
void write_xml_param(const std::string & file_name,
  const std::string & name,
  const std::string & type,
  const std::string & value,
  const bool commented=true);

/// \brief Write a string parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
/// \param commented Determines if this parameter should be commented out
void write_xml_string_param(const std::string & file_name,
  const std::string & name,
  const std::string & value="<value>",
  const bool commented=true);

/// \brief Write an integer valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
/// \param commented Determines if this parameter should be commented out
void write_xml_size_param(const std::string & file_name,
  const std::string & name,
  const std::string & value="<value>",
  const bool commented=true);

/// \brief Write an integer valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
void write_xml_size_param(const std::string & file_name,
  const std::string & name,
  const int value);

/// \brief Write a real valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
/// \param commented Determines if this parameter should be commented out
void write_xml_real_param(const std::string & file_name,
  const std::string & name,
  const std::string & value="<value>",
  const bool commented=true);

/// \brief Write a real valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
void write_xml_real_param(const std::string & file_name,
  const std::string & name,
  const double & value);

/// \brief Write a vector of values to xml
/// \param file_name the name of the xml file
/// \param name the name of the variable
/// \param values the vector of values
void write_xml_high_precision_vector_param(const std::string & file_name,
  const std::string & name,
  const std::vector<double> & values);

/// \brief Write a high precision real valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
void write_xml_high_precision_real_param(const std::string & file_name,
  const std::string & name,
  const double & value);

/// \brief Write a boolean valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
/// \param commented Determines if this parameter should be commented out
void write_xml_bool_param(const std::string & file_name,
  const std::string & name,
  const std::string & value="<value>",
  const bool commented=true);

/// \brief Write a boolean valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The string value of the parameter
void write_xml_bool_param(const std::string & file_name,
  const std::string & name,
  const bool value);

/// \brief Write a boolean valued parameter to file
/// \param file_name The name of the xml file to write to
/// \param name The name of the parameter
/// \param value The bool value of the parameter
/// \param commented Determines if this parameter should be commented out
void write_xml_bool_literal_param(const std::string & file_name,
  const std::string & name,
  const bool value=true,
  const bool commented=true);

/// \brief write an xml file based on a teuchos parameter list
/// \param file_name the name of the output file
/// \param params the Teuchos::ParameterList
// providing an alternative to the teuchos writer since it dumps out a bunch of other fields like "is used", etc.
void write_xml_file(const std::string & file_name,
  const Teuchos::ParameterList & params);

/// write an individual parameter to the file
void write_teuchos_parameter(const std::string & file_name,
  const Teuchos::ParameterList & params,
  const Teuchos::ParameterList::ConstIterator & it);

/// iterate a teuchos sublist and write all the parameters
void write_teuchos_sublist(const std::string & file_name,
  const Teuchos::ParameterList & params);


}// End DICe Namespace

#endif
