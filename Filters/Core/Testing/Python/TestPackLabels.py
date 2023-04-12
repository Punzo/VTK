#!/usr/bin/env python
import vtk

# Enable printing for debugging
debugPrint = 0

# Test the ability to pack segmentation labels into
# contiguous runs. This is useful for discrete isocontouring
# filters such as vtkSurfaceNets3D, vtkDiscreteMarchingCubes,
# and vtkDiscreteFlyingEdges.

# Create a small volume with non-packed voxel values. The output
# data should be packed into unsigned char since there are less
# than 256 labels.
VTK_UCHAR = 3
VTK_INT = 6
xDim = 3
yDim = 3
zDim = 3

numVoxels = xDim * yDim * zDim
image = vtk.vtkImageData()
image.SetDimensions(xDim,yDim,zDim)
image.AllocateScalars(VTK_INT,1)

scalars = image.GetPointData().GetScalars()

# Populate the volume. Create a weird ordering,
# with label gaps and non-contiguous values.
for i in range(0,numVoxels,3):
    idx = numVoxels - i - 1;
    val = 100 + idx
    scalars.SetTuple1(idx,val)
    scalars.SetTuple1(idx-1,val)
    scalars.SetTuple1(idx-2,val)

scalars.SetTuple1(26,0) # make non-contiguous and non-increasing
scalars.SetTuple1(25,0)
scalars.SetTuple1(24,0)

# Print out data as constructed
if debugPrint:
    for i in range(0,numVoxels):
        print(i,scalars.GetTuple1(i))
    print("\n")

# Pack the labels. This should automatically pack into unsigned char.
pack = vtk.vtkPackLabels()
pack.SetInputData(image)
pack.Update()

# See what kind of label we have
labels = pack.GetLabels()
numLabels = labels.GetNumberOfTuples()
if debugPrint:
    print("Number of labels: ",labels.GetNumberOfTuples())
    for i in range(0,numLabels):
        print("Label: ", labels.GetTuple1(i))
    print("\n")

# Look at the resulting volume
outScalars = pack.GetOutput().GetPointData().GetScalars()
dataType = outScalars.GetDataType()
if debugPrint:
    for i in range(0,numVoxels):
        print(i,outScalars.GetTuple1(i))

# Now check for proper output
assert(dataType == VTK_UCHAR)
assert(numLabels == 9)
assert(labels.GetTuple1(0) == 0)
assert(labels.GetTuple1(numLabels-1) == 123)
assert(outScalars.GetTuple1(0) == 1)
assert(outScalars.GetTuple1(numVoxels-1) == 0)
