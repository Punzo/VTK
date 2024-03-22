// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkDGHDivOperators.h"
#include "vtkDGCell.h"
#include "vtkDGOperatorEntry.h"

#include "Basis_HDiv_HexI1Basis.h"
#include "Basis_HDiv_QuadI1Basis.h"
#include "Basis_HDiv_TetI1Basis.h"
#include "Basis_HDiv_TriI1Basis.h"
#include "Basis_HDiv_WdgI1Basis.h"

#include <cmath>
#include <limits>
#include <type_traits>

#define RealT double

namespace vtk
{
namespace basis
{
namespace hdiv
{
VTK_ABI_NAMESPACE_BEGIN

using namespace vtk::literals;

inline RealT abs(RealT x)
{
  return std::fabs(x);
}

void HexI1Basis(const std::array<double, 3>& param, std::vector<double>& basis)
{
  double rr = param[0];
  double ss = param[1];
  double tt = param[2];
  constexpr double eps = std::numeric_limits<RealT>::epsilon();
  (void)rr;
  (void)ss;
  (void)tt;
  (void)eps;

#include "Basis/HDiv/HexI1Basis.h"
}

void QuadI1Basis(const std::array<double, 3>& param, std::vector<double>& basis)
{
  double rr = param[0];
  double ss = param[1];
  double tt = param[2];
  constexpr double eps = std::numeric_limits<RealT>::epsilon();
  (void)rr;
  (void)ss;
  (void)tt;
  (void)eps;

#include "Basis/HDiv/QuadI1Basis.h"
}

void TetI1Basis(const std::array<double, 3>& param, std::vector<double>& basis)
{
  double rr = param[0];
  double ss = param[1];
  double tt = param[2];
  constexpr double eps = std::numeric_limits<RealT>::epsilon();
  (void)rr;
  (void)ss;
  (void)tt;
  (void)eps;

#include "Basis/HDiv/TetI1Basis.h"
}

void TriI1Basis(const std::array<double, 3>& param, std::vector<double>& basis)
{
  double rr = param[0];
  double ss = param[1];
  double tt = param[2];
  constexpr double eps = std::numeric_limits<RealT>::epsilon();
  (void)rr;
  (void)ss;
  (void)tt;
  (void)eps;

#include "Basis/HDiv/TriI1Basis.h"
}

void WdgI1Basis(const std::array<double, 3>& param, std::vector<double>& basis)
{
  double rr = param[0];
  double ss = param[1];
  double tt = param[2];
  constexpr double eps = std::numeric_limits<RealT>::epsilon();
  (void)rr;
  (void)ss;
  (void)tt;
  (void)eps;

#include "Basis/HDiv/WdgI1Basis.h"
}

bool RegisterOperators()
{
  auto& opMap = vtkDGCell::GetOperators();
  auto& basisMap = opMap["Basis"_token]["HDIV"_token];

  // clang-format off
  // # Basis functions
  basisMap["I"_token][1]["vtkDGHex"_token]  = {  6, 3,  HexI1Basis, Basis_HDiv_HexI1Basis };
  basisMap["I"_token][1]["vtkDGQuad"_token] = {  4, 3, QuadI1Basis, Basis_HDiv_QuadI1Basis };
  basisMap["I"_token][1]["vtkDGTet"_token]  = {  4, 3,  TetI1Basis, Basis_HDiv_TetI1Basis };
  basisMap["I"_token][1]["vtkDGTri"_token]  = {  3, 3,  TriI1Basis, Basis_HDiv_TriI1Basis };
  basisMap["I"_token][1]["vtkDGWdg"_token]  = {  5, 3,  WdgI1Basis, Basis_HDiv_WdgI1Basis };

  return true;
}

VTK_ABI_NAMESPACE_END
} // namespace hdiv
} // namespace basis
} // namespace vtk
