#include "hipala_vector.h"

Vec_ operator+(Vec_ Vec_a, Vec_ Vec_b) {
    int i;
    if(Vec_a.len>Vec_b.len) {
    	for(i=0;i<Vec_b.len;i++) {
    		Vec_a.num[i]+=Vec_b.num[i];
		}
	}
	else {
		for(i=0;i<Vec_a.len;i++) {
			Vec_a.num[i]+=Vec_b.num[i];
		}
		for(i=Vec_a.len;i<Vec_b.len;i++) {
			Vec_a.num[i]=Vec_b.num[i];
		}
	}
	return Vec_a;
}

Vec_ operator-(Vec_ Vec_a, Vec_ Vec_b) {
    int i;
    if(Vec_a.len>Vec_b.len) {
    	for(i=0;i<Vec_b.len;i++) {
    		Vec_a.num[i]-=Vec_b.num[i];
		}
	}
	else {
		for(i=0;i<Vec_a.len;i++) {
			Vec_a.num[i]-=Vec_b.num[i];
		}
		for(i=Vec_a.len;i<Vec_b.len;i++) {
			Vec_a.num[i]=-Vec_b.num[i];
		}
	}
	return Vec_a;
}

Vec_ operator*(Vec_ Vec_a, Vec_ Vec_b) {
	int i,l;
	int s=0;
	if(Vec_b.len<Vec_a.len) {
		l=Vec_b.len;
	}
	else {
		l=Vec_a.len;
	}
	for(i=0;i<l;i++) {
		s+=Vec_a.num[i]*Vec_b.num[i];
	}
	return Vec_a; //return a vector? 
}
