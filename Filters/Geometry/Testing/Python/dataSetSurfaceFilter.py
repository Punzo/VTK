#!/usr/bin/env python
import vtk
from vtk.util.misc import vtkGetDataRoot
VTK_DATA_ROOT = vtkGetDataRoot()

# VTK_DEPRECATED_IN_9_1_0
import warnings
warnings.filterwarnings('ignore', category=DeprecationWarning)

# create pipeline - structured grid
#
pl3d = vtk.vtkMultiBlockPLOT3DReader()
pl3d.SetXYZFileName("" + str(VTK_DATA_ROOT) + "/Data/combxyz.bin")
pl3d.SetQFileName("" + str(VTK_DATA_ROOT) + "/Data/combq.bin")
pl3d.SetScalarFunctionNumber(100)
pl3d.SetVectorFunctionNumber(202)
pl3d.Update()
output = pl3d.GetOutput().GetBlock(0)
gf = vtk.vtkDataSetSurfaceFilter()
gf.SetInputData(output)
gMapper = vtk.vtkPolyDataMapper()
gMapper.SetInputConnection(gf.GetOutputPort())
gMapper.SetScalarRange(output.GetScalarRange())
gActor = vtk.vtkActor()
gActor.SetMapper(gMapper)
gf2 = vtk.vtkDataSetSurfaceFilter()
gf2.SetInputData(output)
g2Mapper = vtk.vtkPolyDataMapper()
g2Mapper.SetInputConnection(gf2.GetOutputPort())
g2Mapper.SetScalarRange(output.GetScalarRange())
g2Actor = vtk.vtkActor()
g2Actor.SetMapper(g2Mapper)
g2Actor.AddPosition(0,15,0)
# create pipeline - poly data
#
gf3 = vtk.vtkDataSetSurfaceFilter()
gf3.SetInputConnection(gf.GetOutputPort())
g3Mapper = vtk.vtkPolyDataMapper()
g3Mapper.SetInputConnection(gf3.GetOutputPort())
g3Mapper.SetScalarRange(output.GetScalarRange())
g3Actor = vtk.vtkActor()
g3Actor.SetMapper(g3Mapper)
g3Actor.AddPosition(0,0,15)
gf4 = vtk.vtkDataSetSurfaceFilter()
gf4.SetInputConnection(gf2.GetOutputPort())
gf4.UseStripsOn()
g4Mapper = vtk.vtkPolyDataMapper()
g4Mapper.SetInputConnection(gf4.GetOutputPort())
g4Mapper.SetScalarRange(output.GetScalarRange())
g4Actor = vtk.vtkActor()
g4Actor.SetMapper(g4Mapper)
g4Actor.AddPosition(0,15,15)
# create pipeline - unstructured grid
#
s = vtk.vtkSphere()
s.SetCenter(output.GetCenter())
s.SetRadius(100.0)
#everything
eg = vtk.vtkExtractGeometry()
eg.SetInputData(output)
eg.SetImplicitFunction(s)
gf5 = vtk.vtkDataSetSurfaceFilter()
gf5.SetInputConnection(eg.GetOutputPort())
g5Mapper = vtk.vtkPolyDataMapper()
g5Mapper.SetInputConnection(gf5.GetOutputPort())
g5Mapper.SetScalarRange(output.GetScalarRange())
g5Actor = vtk.vtkActor()
g5Actor.SetMapper(g5Mapper)
g5Actor.AddPosition(0,0,30)
gf6 = vtk.vtkDataSetSurfaceFilter()
gf6.SetInputConnection(eg.GetOutputPort())
gf6.UseStripsOn()
g6Mapper = vtk.vtkPolyDataMapper()
g6Mapper.SetInputConnection(gf6.GetOutputPort())
g6Mapper.SetScalarRange(output.GetScalarRange())
g6Actor = vtk.vtkActor()
g6Actor.SetMapper(g6Mapper)
g6Actor.AddPosition(0,15,30)
# create pipeline - rectilinear grid
#
rgridReader = vtk.vtkRectilinearGridReader()
rgridReader.SetFileName("" + str(VTK_DATA_ROOT) + "/Data/RectGrid2.vtk")
rgridReader.Update()
gf7 = vtk.vtkDataSetSurfaceFilter()
gf7.SetInputConnection(rgridReader.GetOutputPort())
g7Mapper = vtk.vtkPolyDataMapper()
g7Mapper.SetInputConnection(gf7.GetOutputPort())
g7Mapper.SetScalarRange(rgridReader.GetOutput().GetScalarRange())
g7Actor = vtk.vtkActor()
g7Actor.SetMapper(g7Mapper)
g7Actor.SetScale(3,3,3)
gf8 = vtk.vtkDataSetSurfaceFilter()
gf8.SetInputConnection(rgridReader.GetOutputPort())
gf8.UseStripsOn()
g8Mapper = vtk.vtkPolyDataMapper()
g8Mapper.SetInputConnection(gf8.GetOutputPort())
g8Mapper.SetScalarRange(rgridReader.GetOutput().GetScalarRange())
g8Actor = vtk.vtkActor()
g8Actor.SetMapper(g8Mapper)
g8Actor.SetScale(3,3,3)
g8Actor.AddPosition(0,15,0)
# Create the RenderWindow, Renderer and both Actors
ren1 = vtk.vtkRenderer()
renWin = vtk.vtkRenderWindow()
renWin.AddRenderer(ren1)
iren = vtk.vtkRenderWindowInteractor()
iren.SetRenderWindow(renWin)
ren1.AddActor(gActor)
ren1.AddActor(g2Actor)
ren1.AddActor(g3Actor)
ren1.AddActor(g4Actor)
ren1.AddActor(g5Actor)
ren1.AddActor(g6Actor)
ren1.AddActor(g7Actor)
ren1.AddActor(g8Actor)
renWin.SetSize(340,550)
cam1 = ren1.GetActiveCamera()
cam1.SetClippingRange(84,174)
cam1.SetFocalPoint(5.22824,6.09412,35.9813)
cam1.SetPosition(100.052,62.875,102.818)
cam1.SetViewUp(-0.307455,-0.464269,0.830617)
iren.Initialize()
# render the image
#
# prevent the tk window from showing up then start the event loop
# --- end of script --
