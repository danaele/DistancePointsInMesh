#include "DistanceNeighborInMesh.h"


int main ( int argc, char *argv[] )
{
  PARSE_ARGS ;

  vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    
  vtkSmartPointer<vtkPolyDataReader> reader = vtkSmartPointer<vtkPolyDataReader>::New();
 
  reader->SetFileName( mesh.c_str() ) ;
  reader->OpenVTKFile() ;
  reader->Update() ;
  polyData = reader->GetOutput() ;
  //Checked if  file no containing errors
    if ( reader->GetErrorCode() != 0 )
    {
        std::cerr << "Unable to open input file: " << mesh.c_str() << std::endl ;
        return 0 ;
    }   
    
    //std::cout<<"Nb of cells "<<polyData->GetNumberOfCells()<<std::endl;
    
    double AverageDistance = 0;  
    double MinDistance = 0; 
    double MaxDistance = 0;
    
    for(vtkIdType i = 0; i < polyData->GetNumberOfCells(); i++)
    {
    double p[3];
    //polyData->GetPoint(i,p);
    
    vtkCell* cell = polyData->GetCell(i);
 
    vtkTriangle* triangle = dynamic_cast<vtkTriangle*>(cell);
    
    double p0[3];
    double p1[3];
    double p2[3];
    
    triangle->GetPoints()->GetPoint(0, p0);
   // std::cout << "p0: " << p0[0] << " " << p0[1] << " " << p0[2] << std::endl;
    
    triangle->GetPoints()->GetPoint(1, p1);
   // std::cout << "p1: " << p1[0] << " " << p1[1] << " " << p1[2] << std::endl;
    
    triangle->GetPoints()->GetPoint(2, p2);
  //  std::cout << "p2: " << p2[0] << " " << p2[1] << " " << p2[2] << std::endl;
    
     double squaredDistance = vtkMath::Distance2BetweenPoints(p0, p1);
     double distance0 = sqrt(squaredDistance);
     
     squaredDistance = vtkMath::Distance2BetweenPoints(p0, p2);
     double distance1 = sqrt(squaredDistance);
     
     squaredDistance = vtkMath::Distance2BetweenPoints(p1, p2);
     double distance2 = sqrt(squaredDistance);
     
     //Average
    AverageDistance = AverageDistance + distance0 + distance1 + distance2;
     
     //Min
     if( distance0 < distance1 && distance0 < distance2) 
      {
        if( i == 0 )
        {
          MinDistance = distance0;
        }
        else if ( i != 0 && distance0 < MinDistance)
        {
            MinDistance = distance0;
        }
      }
      else if ( distance1 < distance0 && distance1 < distance2)
      {
        if( i == 0 )
        {
          MinDistance = distance1;
        }
        else if ( i != 0 && distance1 < MinDistance)
        {
            MinDistance = distance1;
        }       
      }
      else
      {
        if( i == 0 )
        {
          MinDistance = distance2;
        }
        else if ( i != 0 && distance2 < MinDistance)
        {
            MinDistance = distance2;
        }    
      }
     
     
     //Max 
      if( distance0 > distance1 && distance0 > distance2) 
      {
        if( i == 0 )
        {
          MaxDistance = distance0;
        }
        else if ( i != 0 && distance0 > MaxDistance)
        {
            MaxDistance = distance0;
        }
      }
      else if ( distance1 > distance0 && distance1 > distance2)
      {
        if( i == 0 )
        {
          MaxDistance = distance1;
        }
        else if ( i != 0 && distance1 > MaxDistance)
        {
            MaxDistance = distance1;
        }       
      }
      else
      {
        if( i == 0 )
        {
          MaxDistance = distance2;
        }
        else if ( i != 0 && distance2 > MaxDistance)
        {
            MaxDistance = distance2;
        } 
      }
    }
 
    AverageDistance = AverageDistance / (3*polyData->GetNumberOfCells());
    
    std::cout<<"Average distance : "<<AverageDistance<<std::endl;
    std::cout<<"Minimum distance : "<<MinDistance<<std::endl;
    std::cout<<"maximum distance : "<<MaxDistance<<std::endl;
   // for(vtkIdType i = 0; i < polyData->GetNumberOfPoints(); i++)
      
  return 0; 
}
