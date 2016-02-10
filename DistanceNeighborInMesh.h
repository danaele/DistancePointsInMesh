#include <cstdio> 
#include <DistanceNeighborInMeshCLP.h>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkDataReader.h>
#include <vtkPolyDataReader.h>

#include <vtkPolyDataWriter.h>
#include <vtkThreshold.h>
#include <vtkThresholdPoints.h>
#include <vtkCellArray.h>
#include <vtkUnstructuredGrid.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vtkPointData.h>
#include <list>
#include <map>
#include <iterator>

#include <vtkVersion.h>
#include "vtkSmartPointer.h"
 
#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCellArray.h"
#include "vtkImageDataGeometryFilter.h"
#include "vtkPoints.h"
#include "vtkPolyData.h"
#include "vtkPolyDataCollection.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSphereSource.h"
#include "vtkTriangleFilter.h"
#include "vtkXMLPolyDataReader.h"
#include <vtkTriangle.h>
#include <vtkMath.h>

#include "vtkContourWidget.h"
#include "vtkOrientedGlyphContourRepresentation.h"
#include "vtkPolygonalSurfacePointPlacer.h"
#include "vtkPolygonalSurfaceContourLineInterpolator.h"


