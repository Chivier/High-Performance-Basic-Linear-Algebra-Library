#include "hipala_vector.h"

Vec_ operator+(Vec_ Vec_a, Vec_ Vec_b) {
	Vec_ Vec_result;
	if( Vec_a.len!= Vec_b.len){
		std::cout<< "A "<< Vec_a.len
		         << "dimensional vector can't add with a "
				 << Vec_a.len<< "dimensional vector!";
		exit(1);
	}
	else{
		Vec_result.len= Vec_a.len;
		for(int i=0; i< Vec_a.len; i++)
			Vec_result.num[i]= Vec_a.num[i]+ Vec_b.num[i];
	}
    return Vec_result;
}

Vec_ operator-(Vec_ Vec_a, Vec_ Vec_b) {
    Vec_ Vec_result;
	if( Vec_a.len!= Vec_b.len){
		std::cout<< "A "<< Vec_a.len
		         << "dimensional vector can't minus with a "
				 << Vec_a.len<< "dimensional vector!";
		exit(1);
	}
	else{
		Vec_result.len= Vec_a.len;
		for(int i=0; i< Vec_a.len; i++)
			Vec_result.num[i]= Vec_a.num[i]- Vec_b.num[i];
	}
    return Vec_result;
}

//??????Vec_ ---> double
double operator*(Vec_ Vec_a, Vec_ Vec_b) {
	double result=0;
	if(Vec_a.len!=Vec_b.len) {
		std::cout<<"";
		exit(1);
	}
	for(int i=0;i<Vec_a.len;i++)
		result+=Vec_a.num[i]*Vec_b.num[i];
    return result;
}
