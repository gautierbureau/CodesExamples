#include <iostream>
#include <memory>

#include "Seldon.hxx"

#include "SeldonSolver.hxx"

#include "matrix_sparse/IOMatrixMarket.cxx"

int main () 
{
	Seldon::Matrix<double> mat;
	
	Seldon::Matrix<double, Seldon::General, Seldon::ArrayRowSparse> A;
	Seldon::ReadMatrixMarket("fidap001.mtx", A);
	
	//A.Print();
	
	Seldon::Vector<double> Ptr;
	Seldon::Vector<double> Ind;
	Seldon::Vector<double> Val;
	
	Seldon::General prop;
	Seldon::ConvertToCSC(A, prop, Ptr, Ind, Val);
	
	Ptr.WriteText("ptr.dat");
	Ind.WriteText("ind.dat");
	Val.WriteText("val.dat");
   
   return 0;
}
