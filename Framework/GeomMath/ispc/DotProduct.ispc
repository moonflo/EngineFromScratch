extern void MulByElement(uniform const float a[], uniform const float b[], uniform float result[], uniform const int count);

// export void DotProduct(uniform const float a[], uniform const float b[], uniform float* uniform result, uniform const int count) {
// 	*result = 0;
// 	uniform float * uniform r = uniform new uniform float [count];
// 	MulByElement(a, b, r, count);
// 	foreach_active(i) {
// 		*result += r[i];
// 	}
// 	delete[] r;
// }

export void DotProduct(uniform const float a[], uniform const float b[], uniform float* uniform result, uniform const int count) { 
	varying float v_result = 0; 
	uniform float * uniform r = uniform new uniform float [count]; 
	MulByElement(a, b, r, count); 
	foreach (index = 0 ... count) { 
		v_result += r[index]; 
	} 
	delete[] r; 
	*result = reduce_add(v_result); 
}