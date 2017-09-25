/*==================================================================

  Program:   Visualization Toolkit
  Module:    TestHyperTreeGridTernary3DAxisCut.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

===================================================================*/
// .SECTION Thanks
// This test was written by Philippe Pebay, Kitware 2012
// This test was revised by Philippe Pebay, 2016
// This work was supported by Commissariat a l'Energie Atomique (CEA/DIF)

#include "vtkHyperTreeGrid.h"
#include "vtkHyperTreeGridAxisCut.h"
#include "vtkHyperTreeGridGeometry.h"
#include "vtkHyperTreeGridSource.h"

#include "vtkCamera.h"
#include "vtkCellData.h"
#include "vtkDataSetMapper.h"
#include "vtkNew.h"
#include "vtkOutlineFilter.h"
#include "vtkProperty.h"
#include "vtkPolyDataMapper.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkShrinkFilter.h"

int TestHyperTreeGridTernary3DAxisCut( int argc, char* argv[] )
{
  // Hyper tree grid
  vtkNew<vtkHyperTreeGridSource> htGrid;
  htGrid->SetMaximumLevel( 5 );
  htGrid->SetGridSize( 3, 3, 2 );
  htGrid->SetGridScale( 1.5, 1., .7 );
  htGrid->SetDimension( 3 );
  htGrid->SetBranchFactor( 3 );
  htGrid->SetDescriptor( "RRR .R. .RR ..R ..R .R.|R.......................... ........................... ........................... .............R............. ....RR.RR........R......... .....RRRR.....R.RR......... ........................... ........................... ...........................|........................... ........................... ........................... ...RR.RR.......RR.......... ........................... RR......................... ........................... ........................... ........................... ........................... ........................... ........................... ........................... ............RRR............|........................... ........................... .......RR.................. ........................... ........................... ........................... ........................... ........................... ........................... ........................... ...........................|........................... ..........................." );

  // Outline
  vtkNew<vtkOutlineFilter> outline;
  outline->SetInputConnection( htGrid->GetOutputPort() );

  // Axis cuts
  vtkNew<vtkHyperTreeGridAxisCut> axisCut1;
  axisCut1->SetInputConnection( htGrid->GetOutputPort() );
  axisCut1->SetPlaneNormalAxis( 0 );
  axisCut1->SetPlanePosition( 1.99 );
  vtkNew<vtkHyperTreeGridAxisCut> axisCut2;
  axisCut2->SetInputConnection( htGrid->GetOutputPort() );
  axisCut2->SetPlaneNormalAxis( 2 );
  axisCut2->SetPlanePosition( .35 );

  // Geometries
  vtkNew<vtkHyperTreeGridGeometry> geometry1;
  geometry1->SetInputConnection( axisCut1->GetOutputPort() );
  geometry1->Update();
  vtkNew<vtkHyperTreeGridGeometry> geometry2;
  geometry2->SetInputConnection( axisCut2->GetOutputPort() );
  geometry2->Update();
  vtkPolyData* pd = geometry2->GetPolyDataOutput();

  // Shrinks
  vtkNew<vtkShrinkFilter> shrink1;
  shrink1->SetInputConnection( geometry1->GetOutputPort() );
  shrink1->SetShrinkFactor( .8 );
  vtkNew<vtkShrinkFilter> shrink2;
  shrink2->SetInputConnection( geometry2->GetOutputPort() );
  shrink2->SetShrinkFactor( .8 );

  // Mappers
  vtkMapper::SetResolveCoincidentTopologyToPolygonOffset();
  vtkNew<vtkDataSetMapper> mapper1;
  mapper1->SetInputConnection( shrink1->GetOutputPort() );
  mapper1->SetScalarRange( pd->GetCellData()->GetScalars()->GetRange() );
  vtkNew<vtkPolyDataMapper> mapper2;
  mapper2->SetInputConnection( geometry1->GetOutputPort() );
  mapper2->ScalarVisibilityOff();
  vtkNew<vtkPolyDataMapper> mapper3;
  mapper3->SetInputConnection( outline->GetOutputPort() );
  mapper3->ScalarVisibilityOff();
  vtkNew<vtkDataSetMapper> mapper4;
  mapper4->SetInputConnection( shrink2->GetOutputPort() );
  mapper4->SetScalarRange( pd->GetCellData()->GetScalars()->GetRange() );
  vtkNew<vtkPolyDataMapper> mapper5;
  mapper5->SetInputConnection( geometry2->GetOutputPort() );
  mapper5->ScalarVisibilityOff();

  // Actors
  vtkNew<vtkActor> actor1;
  actor1->SetMapper( mapper1 );
  vtkNew<vtkActor> actor2;
  actor2->SetMapper( mapper2 );
  actor2->GetProperty()->SetRepresentationToWireframe();
  actor2->GetProperty()->SetColor( .7, .7, .7 );
  vtkNew<vtkActor> actor3;
  actor3->SetMapper( mapper3 );
  actor3->GetProperty()->SetColor( .1, .1, .1 );
  actor3->GetProperty()->SetLineWidth( 1 );
  vtkNew<vtkActor> actor4;
  actor4->SetMapper( mapper4 );
  vtkNew<vtkActor> actor5;
  actor5->SetMapper( mapper5 );
  actor5->GetProperty()->SetRepresentationToWireframe();
  actor5->GetProperty()->SetColor( .7, .7, .7 );

  // Camera
  vtkHyperTreeGrid* ht = htGrid->GetHyperTreeGridOutput();
  double bd[6];
  ht->GetBounds( bd );
  vtkNew<vtkCamera> camera;
  camera->SetClippingRange( 1., 100. );
  camera->SetFocalPoint( ht->GetCenter() );
  camera->SetPosition( -.8 * bd[1], 2.1 * bd[3], -4.8 * bd[5] );

  // Renderer
  vtkNew<vtkRenderer> renderer;
  renderer->SetActiveCamera( camera );
  renderer->SetBackground( 1., 1., 1. );
  renderer->AddActor( actor1 );
  renderer->AddActor( actor2 );
  renderer->AddActor( actor3 );
  renderer->AddActor( actor4 );
  renderer->AddActor( actor5 );

  // Render window
  vtkNew<vtkRenderWindow> renWin;
  renWin->AddRenderer( renderer );
  renWin->SetSize( 400, 400 );
  renWin->SetMultiSamples( 0 );

  // Interactor
  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow( renWin );

  // Render and test
  renWin->Render();

  int retVal = vtkRegressionTestImage( renWin );
  if ( retVal == vtkRegressionTester::DO_INTERACTOR )
  {
    iren->Start();
  }

  return !retVal;
}
