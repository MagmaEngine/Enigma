#ifndef _ENIGMA_H
#define _ENIGMA_H

#define PI 3.1415926535897932384626433832795L

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef NULL
#define NULL (void*)(0)
#endif

#ifndef _UINT
#define _UINT
typedef unsigned int uint;
#endif // _UINT

#ifndef E_UNUSED
#define E_UNUSED(x) (void)(x)
#endif

#ifdef E_DOUBLE_PRECISION
typedef double EFloat;
#else
typedef float EFloat;
#endif

#ifdef E_MEM_DEBUG

/* ----- Debugging -----
If E_MEM_DEBUG  is enabled, the memory debugging system will create macros that replace malloc, free and realloc and allows the system to keep track of and report where memory is beeing allocated, how much and if the memory is beeing freed. This is very useful for finding memory leaks in large applications. The system can also over allocate memory and fill it with a magic number and can therfor detect if the application writes outside of the allocated memory. if E_EXIT_CRASH is defined, then exit(); will be replaced with a funtion that writes to NULL. This will make it trivial ti find out where an application exits using any debugger., */

void e_debug_memory_init(void (*lock)(void *mutex), void (*unlock)(void *mutex), void *mutex); /* Required for memory debugger to be thread safe */
void *e_debug_mem_malloc(size_t size, char *file, uint line); /* Replaces malloc and records the c file and line where it was called*/
void *e_debug_mem_realloc(void *pointer, size_t size, char *file, uint line); /* Replaces realloc and records the c file and line where it was called*/
void e_debug_mem_free(void *buf); /* Replaces free and records the c file and line where it was called*/
void e_debug_mem_print(uint min_allocs); /* Prints out a list of all allocations made, their location, how much memorey each has allocated, freed, and how many allocations have been made. The min_allocs parameter can be set to avoid printing any allocations that have been made fewer times then min_allocs */
void e_debug_mem_reset(void); /* f_debug_mem_reset allows you to clear all memory stored in the debugging system if you only want to record allocations after a specific point in your code*/
bool e_debug_memory(void); /*f_debug_memory checks if any of the bounds of any allocation has been over written and reports where to standard out. The function returns TRUE if any error was found*/

#define malloc(n) e_debug_mem_malloc(n, __FILE__, __LINE__) /* Replaces malloc. */
#define realloc(n, m) e_debug_mem_realloc(n, m, __FILE__, __LINE__) /* Replaces realloc. */
#define free(n) e_debug_mem_free(n) /* Replaces free. */

#endif // E_MEM_DEBUG

// Crash on exit.
#ifdef E_EXIT_CRASH
void exit_crash(uint i);
#define exit(n) exit_crash(n);
#endif

// ------------ Logging -------------
enum ELogLevel {
	E_LOG_DEBUG,
	E_LOG_INFO,
	E_LOG_WARNING,
	E_LOG_ERROR,
	E_LOG_MAX
};

void e_log_message(enum ELogLevel level, const wchar_t *channel, const wchar_t *format, ...);

// ------------ Fast RNG ------------

// ranged 0 to 1
float e_randf(uint32_t index);
double e_randd(uint32_t index);

// ranged -1 to 1
float e_randnf(uint32_t index);
double e_randnd(uint32_t index);

// rand uint
uint e_randi(uint32_t index);

// ------------ Dynamic Arrays ------------
// only store pointer types
typedef struct {
	void *arr;
	size_t item_size;
	uint num_items;
	uint item_cap;
} EDynarr;

EDynarr *e_dynarr_init(size_t item_size, uint item_cap);
void e_dynarr_deinit(EDynarr *d);
void e_dynarr_add(EDynarr *d, void *item);
int e_dynarr_contains(EDynarr *d, void *item);
int e_dynarr_remove_unordered(EDynarr *d, uint index);
int e_dynarr_remove_unordered_ptr(EDynarr *d, void *item);
int e_dynarr_remove_ordered(EDynarr *d, uint index);

// ------------- Threads ---------------
#ifdef _ENIGMA_LINUX
#include <pthread.h>
typedef pthread_t EThread;
typedef void *EThreadArguments;
typedef void *EThreadResult;
typedef EThreadResult (*EThreadFunction)(void *);
typedef pthread_mutex_t EMutex;
#endif
#ifdef _ENIGMA_WINDOWS
#include <windows.h>
typedef HANDLE EThread;
typedef void *EThreadArguments;
typedef DWORD EThreadResult;
typedef EThreadResult (*EThreadFunction)(void *);
typedef CRITICAL_SECTION EMutex;
#endif
void e_mutex_lock(EMutex *mutex);
void e_mutex_unlock(EMutex *mutex);
void e_mutex_init(EMutex *mutex);
void e_mutex_destroy(EMutex *mutex);

EThread e_thread_create(EThreadFunction func, EThreadArguments args);
EThread e_thread_self(void);
void e_thread_join(EThread thread);
void e_thread_detach(EThread thread);


// ------------ Integer math --------------
int e_maxi(int a, int b);
int e_mini(int a, int b);

// ------------ Vector Math ------------
//#define d_sqrt sqrt /* replaced sqrt with carmacks  inverse sqrt aproximation */

float e_sqrtf(float number); /* replaced sqrt with carmacks  inverse sqrt aproximation */
float e_length2f(float *vec); /* Computes the length of a vector 2D for 32 bit floats.*/
float e_length3f(float *vec); /* Computes the length of a vector 3D for 32 bit floats.*/
float e_distance2f(float *a, float *b); /* Computes the distance between two points in 2D for 32 bit floats.*/
float e_distance3f(float *a, float *b); /* Computes the distance between two points in 3D for 32 bit floats.*/
float e_dot2f(float *a, float *b); /* Computes the dot product between two points in 2D for 32 bit floats.*/
float e_dot3f(float *a, float *b); /* Computes the dot product between two points in 3D for 32 bit floats.*/
void e_cross2f(float *output, float *a, float *b); /* Computes cross product between two points in 2D for 32 bit floats.*/
void e_cross3f(float *output, float *a, float *b); /* Computes cross product between two points in 3D for 32 bit floats.*/
void e_normalize2f(float *vec); /* Normalizes a 2D vector of 32 bit floats.*/
void e_normalize3f(float *vec); /* Normalizes a 3D vector of 32 bit floats.*/
void e_normalize4f(float *vec); /* Normalizes a 4D vector of 32 bit floats (useful for quaternions).*/
void e_normal2f(float *output, float *a, float *b); /* Generates a normal from 2 points on a line. */
void e_normal3f(float *output, float *a, float *b, float *c); /* Generates a normal from 3 points on a plane. */
void e_reflect2f(float *output, float *pos, float *normal); /* Reflects a position to a normal plane in 2D for 32 bit floats.*/
void e_reflect3f(float *output, float *pos, float *normal); /* Reflects a position to a normal plane in 3D for 32 bit floats.*/
void e_project2f(float *output, float *pos, float *vec); /* Projects a point (pos) onto a line defined by (vec) in 2D for 32 bit floats.*/
void e_project3f(float *output, float *pos, float *vec); /* Projects a point (pos) onto a line defined by (vec) in 3D for 32 bit floats.*/
void e_intersect2f(float *output, float *line_a0, float *line_a1, float *line_b0, float *line_b1); /* Computes the intersection between two lines in 2D for 32 bit floats.*/

double e_length2d(double *vec); /* Computes the length of a vector 2D for 64 bit doubles.*/
double e_length3d(double *vec); /* Computes the length of a vector 3D for 64 bit doubles.*/
double e_distance2d(double *a, double *b); /* Computes the distance between two points in 2D for 64 bit doubles.*/
double e_distance3d(double *a, double *b); /* Computes the distance between two points in 3D for 64 bit doubles.*/
double e_dot2d(double *a, double *b); /* Computes the dot product between two points in 2D for 64 bit doubles.*/
double e_dot3d(double *a, double *b); /* Computes the dot product between two points in 3D for 64 bit doubles.*/
void e_cross2d(double *output, double *a, double *b); /* Computes cross product between two points in 2D for 64 bit doubles.*/
void e_cross3d(double *output, double *a, double *b); /* Computes cross product between two points in 3D for 64 bit doubles.*/
void e_normalize2d(double *vec); /* Normalizes a 2D vector of 64 bit doubles.*/
void e_normalize3d(double *vec); /* Normalizes a 3D vector of 64 bit doubles.*/
void e_normalize4d(double *vec); /* Normalizes a 4D vector of 64 bit doubles (useful for quaternions).*/
void e_normal2d(double *output, double *a, double *b); /* Generates a normal from 2 points on a line. */
void e_normal3d(double *output, double *a, double *b, double *c); /* Generates a normal from 3 points on a plane. */
void e_reflect2d(double *output, double *pos, double *normal); /* Reflects a position to a normal plane in 2D for 64 bit doubles.*/
void e_reflect3d(double *output, double *pos, double *normal); /* Reflects a position to a normal plane in 3D for 64 bit doubles.*/
void e_project2d(double *output, double *pos, double *vec); /* Projects a point (pos) onto a line defined by (vec) in 2D for 64 bit doubles.*/
void e_project3d(double *output, double *pos, double *vec); /* Projects a point (pos) onto a line defined by (vec) in 3D for 64 bit doubles.*/
void e_intersect2d(double *output, double *line_a0, double *line_a1, double *line_b0, double *line_b1); /* Computes the intersection between two lines in 2D for 64 bit doubles.*/

/*------- Integer vector math -------------

Vector math for integer types. */

// long e_sqrti(long value); /* Integer square root.*/
bool e_normalize_2di(int *point, int fixed_point_multiplyer); /* Normalizes a 2D vector of integers. The fixed_point_multiplyer is used to set what is considerd to be one. */
bool e_normalize_3di(int *point, int fixed_point_multiplyer); /* Normalizes a 2D vector of integers. The fixed_point_multiplyer is used to set what is considerd to be one. */
void e_intersect2di(int *output, int *line_a0, int *line_a1, int *line_b0, int *line_b1); /* Inter sects two 2d integer lines. */

/*------- Matrix operations ------------------------
Matrix operations for 4x4 matrices.*/

void e_matrix_clearf(float *matrix); /* Clears a 4x4 32 bit float matrix to an identity matrix.*/
void e_matrix_cleard(double *matrix); /* Clears a 4x4 64 bit double matrix to an identity matrix.*/
void e_transform3f(float *output, const float *matrix, const float x, const float y, const float z); /* Transforms a 3D point with a 4x4 32 bit float matrix.*/
void e_transform3d(double *out, const double *matrix, const double x, const double y, const double z);  /* Transforms a 3D point with a 4x4 64 bit double matrix.*/
void e_transform4f(float *output, const float *matrix, const float x, const float y, const float z, const double w); /* Transforms a 4D point with a 4x4 32 bit float matrix.*/
void e_transform4d(double *out, const double *matrix, const double x, const double y, const double z, const double w); /* Transforms a 4D point with a 4x4 64 bit double matrix.*/
void e_transforminv3f(float *out, const float *matrix, float x, float y, float z);
void e_transforminv3d(double *out, const double *matrix, double x, double y, double z);
void e_matrix_multiplyf(float *output, const float *a, const float *b); /* Multiplies two 4x4 32 bit float matrices.*/
void e_matrix_multiplyd(double *output, const double *a, const double *b); /* Multiplies two 4x4 64 bit double matrices.*/
void e_matrix_reverse4f(float *output, const float *matrix); /* Reverces a 4x4 32 bit float matrix.*/
void e_matrix_reverse4d(double *output, const double *matrix); /* Reverces a 4x4 64 bit double matrix.*/
void e_quaternion_to_matrixf(float *matrix, float x, float y, float z, float w); /* Converts a 32 bit float quaternoion to a 4x4 32 bit float matrix.*/
void e_quaternion_to_matrixd(double *matrix, double x, double y, double z, double w); /* Converts a 64 bit double quaternoion to a 4x4 64 bit double matrix.*/
void e_matrix_to_quaternionf(float *quaternion, float *matrix); /* Converts a 4x4 32 bit float matrix to a 32 bit float quaternoion.*/
void e_matrix_to_quaterniond(double *quaternion, double *matrix); /* Converts a 4x4 64 bit double matrix to a 64 bit double quaternoion.*/
void e_matrix_to_pos_quaternion_scalef(float *matrix, float *pos, float *quaternion, float *scale); /* Converts a 4x4 32 bit float matrix to a 32 bit float position, scale and quaternoion.*/
void e_matrix_to_pos_quaternion_scaled(double *matrix, double *pos, double *quaternion, double *scale); /* Converts a 4x4 64 bit double matrix to a 64 bit double position, scale and quaternoion.*/
void e_pos_quaternion_scale_to_matrixf(float *pos, float *quaternion, float *scale, float *matrix); /* Converts a 32 bit float position, scale and quaternoion to a 4x4 32 bit float matrix.*/
void e_pos_quaternion_scale_to_matrixd(double *pos, double *quaternion, double *scale, double *matrix); /* Converts a 64 bit double position, scale and quaternoion to a 4x4 64 bit double matrix.*/

/*------- Matrix Creation ------------------------
These functions lets you create a matrix from two points and an optional origo (The origo can be left as NULL). The first vector dominates and the second will be used to determain rotation arround trhe first vecrtor*/

void e_matrixxyf(float *matrix, const float *origo, const float *point_a, const float *point_b); /* Lets you create a 32 bit float 4x4 matrix using the X and Y vector */
void e_matrixxzf(float *matrix, const float *origo, const float *point_a, const float *point_b); /* Lets you create a 32 bit float 4x4 matrix using the X and Z vector */
void e_matrixyxf(float *matrix, const float *origo, const float *point_a, const float *point_b); /* Lets you create a 32 bit float 4x4 matrix using the Y and X vector */
void e_matrixyzf(float *matrix, const float *origo, const float *point_a, const float *point_b); /* Lets you create a 32 bit float 4x4 matrix using the Y and Z vector */
void e_matrixzxf(float *matrix, const float *origo, const float *point_a, const float *point_b); /* Lets you create a 32 bit float 4x4 matrix using the Z and X vector */
void e_matrixzyf(float *matrix, const float *origo, const float *point_a, const float *point_b); /* Lets you create a 32 bit float 4x4 matrix using the Z and Y vector */
void e_matrixxyd(double *matrix, const double *origo, const double *point_a, const double *point_b); /* Lets you create a 64 bit double 4x4 matrix using the X and Y vector */
void e_matrixxzd(double *matrix, const double *origo, const double *point_a, const double *point_b); /* Lets you create a 64 bit double 4x4 matrix using the X and Z vector */
void e_matrixyxd(double *matrix, const double *origo, const double *point_a, const double *point_b); /* Lets you create a 64 bit double 4x4 matrix using the Y and X vector */
void e_matrixyzd(double *matrix, const double *origo, const double *point_a, const double *point_b); /* Lets you create a 64 bit double 4x4 matrix using the Y and Z vector */
void e_matrixzxd(double *matrix, const double *origo, const double *point_a, const double *point_b); /* Lets you create a 64 bit double 4x4 matrix using the Z and X vector */
void e_matrixzyd(double *matrix, const double *origo, const double *point_a, const double *point_b); /* Lets you create a 64 bit double 4x4 matrix using the Z and Y vector */

/* ---- Splines ----
Multi dimentional bicubic spline segments.*/

float e_splinef(float f, float v0, float v1, float v2, float v3); /* 1D 32 bit float spline. */
void e_spline2df(float *out, float f, float *v0, float *v1, float *v2, float *v3); /* 2D 32 bit float spline. */
void e_spline3df(float *out, float f, float *v0, float *v1, float *v2, float *v3); /* 3D 32 bit float spline. */
void e_spline4df(float *out, float f, float *v0, float *v1, float *v2, float *v3); /* 4D 32 bit float spline. */
double e_splined(double f, double v0, double v1, double v2, double v3); /* 1D 64 bit double spline. */
void e_spline2dd(double *out, double f, double *v0, double *v1, double *v2, double *v3); /* 2D 64 bit double spline. */
void e_spline3dd(double *out, double f, double *v0, double *v1, double *v2, double *v3); /* 3D 64 bit double spline. */
void e_spline4dd(double *out, double f, double *v0, double *v1, double *v2, double *v3); /* 4D 64 bit double spline. */

/* ---- Wiggle ----
Wiggle is a useful animation function that creates a value that over f moves in a psevdo random way. The motion can be compared to a fly cirkling a lightsource */

float e_wigglef(float f, float size); /* 1D 32 bit float wiggle*/
void e_wiggle2df(float *out, float f, float size); /* 2D 32 bit float wiggle*/
void e_wiggle3df(float *out, float f, float size); /* 3D 32 bit float wiggle*/
double e_wiggled(double f, double size); /* 1D 64 bit double wiggle*/
void e_wiggle2dd(double *out, double f, double size); /* 2D 64 bit double wiggle*/
void e_wiggle3dd(double *out, double f, double size); /* 3D 64 bit double wiggle*/

/* ---- Smooth step ----
A fast smooth step funtion that eases in as it closes on on zero and one.*/

float e_smooth_stepf(float f); /* 32 bit float smoothstep. */
double e_smooth_stepd(double f); /* 64 bit double smoothstep. */

/* ------ Perlin noise --------
Single and multi dimentional implementations of Perlin noise. Very useful for procedural data generation */

float e_noisef(float f); /* Single octave 1D 32 bit float noise.*/
float e_noise2f(float x, float y); /* Single octave 2D 32 bit float noise.*/
float e_noise3f(float x, float y, float z); /* Single octave 3D 32 bit float noise.*/
float e_noiserf(float f, uint recursions); /* Recursive 1D 32 bit float noise.*/
float e_noiser2f(float x, float y, uint recursions); /* Recursive 2D 32 bit float noise.*/
float e_noiser3f(float x, float y, float z, uint recursions); /* Recursive 3D 32 bit float noise.*/
double e_noised(double f); /* Single octave 1D 64 bit double noise.*/
double e_noise2d(double x, double y); /* Single octave 2D 64 bit double noise.*/
double e_noise3d(double x, double y, double z); /* Single octave 3D 64 bit double noise.*/
double e_noiserd(double f, uint recursions); /* Recursive 1D 64 bit double noise.*/
double e_noiser2d(double x, double y, uint recursions); /* Recursive 2D 64 bit double noise.*/
double e_noiser3d(double x, double y, double z, uint recursions); /* Recursive 3D 64 bit double noise.*/

/* tiled versions of all perlin noises*/

float e_noisetf(float f, int period); /* Single octave 1D 32 bit float tiled noise.*/
float e_noiset2f(float x, float y, int period); /* Single octave 2D 32 bit float tiled noise.*/
float e_noiset3f(float x, float y, float z, int period); /* Single octave 3D 32 bit float tiled noise.*/
float e_noisertf(float f, uint recursions, int period); /* Recursive 1D 32 bit float tiled noise.*/
float e_noisert2f(float x, float y, uint recursions, int period); /* Recursive 2D 32 bit float tiled noise.*/
float e_noisert3f(float x, float y, float z, uint recursions, int period); /* Recursive 3D 32 bit float tiled noise.*/
double e_noisetd(double f, int period); /* Single octave 1D 64 bit double tiled noise.*/
double e_noiset2d(double x, double y, int period); /* Single octave 2D 64 bit double tiled noise.*/
double e_noiset3d(double x, double y, double z, int period); /* Single octave 3D 64 bit double tiled noise.*/
double e_noisertd(double f, uint recursions, int period); /* Recursive 1D 64 bit double tiled noise.*/
double e_noisert2d(double x, double y, uint recursions, int period); /* Recursive 2D 64 bit double tiled noise.*/
double e_noisert3d(double x, double y, double z, uint recursions, int period); /* Recursive 3D 64 bit double tiled noise.*/

/* ------ Snap --------
Snaps a floating point to the nearest step */

float e_snapf(float f, float step_size); /* 32 bit float step function. */
double e_snapd(double f, double step_size); /* 64 bit double step function. */

/* ---- Color space --------------
These functions lets you convert colors between useful color spaces like RGB (For rendering), HSV (For user interfaces), XYZ  (for a luminance corrected RGB) and LAB (For color correction). */

void e_rgb_to_hsv(float *hsv, float r, float g, float b); /* Converts from RBG to HSV.*/
void e_hsv_to_rgb(float *rgb, float h, float s, float v); /* Converts from HSV to RGB.*/

void e_rgb_to_xyz(float *xyz, float r, float g, float b); /* Converts from RBG to XYZ.*/
void e_xyz_to_rgb(float *rgb, float x, float y, float z); /* Converts from XYZ to RGB.*/

void e_xyz_to_lab(float *lab, float x, float y, float z); /* Converts from XYZ to LAB.*/
void e_lab_to_xyz(float *xyz, float l, float a, float b); /* Converts from LAB to XYZ.*/

void e_rgb_to_lab(float *lab, float r, float g, float b); /* Converts from RBG to LAB.*/
void e_lab_to_rgb(float *rgb, float l, float a, float b); /* Converts from LAB to RGB.*/

/* ---- Triangle intersection --------------
This is a very fast implementation of line to triabngle intersection. Useful for any kind of raytraceing. */

bool e_raycast_trif(float orig[3], float dir[3], float vert0[3], float vert1[3], float vert2[3], float *t, float *u, float *v); /* 32 bit float line to triabngle intersection without backface culling. */
bool e_raycast_tri_cullf(float orig[3], float dir[3], float vert0[3], float vert1[3], float vert2[3], float *t, float *u, float *v); /* 32 bit float line to triabngle intersection with backface culling. */

bool e_raycast_trid(double orig[3], double dir[3], double vert0[3], double vert1[3], double vert2[3], double *t, double *u, double *v);/* 64 bit double line to triabngle intersection without backface culling. */
bool e_raycast_tri_culld(double orig[3], double dir[3], double vert0[3], double vert1[3], double vert2[3], double *t, double *u, double *v);/* 64 bit float line to triabngle intersection with backface culling. */

/* Text */

uint	e_find_next_word(char *text);
bool	e_find_word_compare(char *text_a, char *text_b);
uint	e_text_copy(uint length, char *dest, char *source);
bool	e_text_compare(char *text_a, char *text_b);
char	*e_text_copy_allocate(char *source);
uint	e_word_copy(uint length, char *dest, char *source);
uint	e_text_copy_until(uint length, char *dest, char *source, char *until);
bool	e_text_filter(char *text, char *filter);

/* ---- A* path finding ------
A very fast algorithem for path finding. */

uint *e_path_find(uint *output_count, uint cell_count, uint naighbour_max_count, uint start, uint goal, uint (* naighbout_func)(uint start, uint goal, uint *list, float *cost, float *dist, void *user), void *user, uint max_cells);

#ifdef E_DOUBLE_PRECISION

#define e_length2 e_length2d
#define e_length3 e_length3d
#define e_distance2 e_distance2d
#define e_distance3 e_distance3d
#define e_dot2 e_dot2d
#define e_dot3 e_dot3d
#define e_cross2 e_cross2d
#define e_cross3 e_cross3d
#define e_normalize2 e_normalize2d
#define e_normalize3 e_normalize3d
#define e_normalize4 e_normalize4d
#define e_reflect2 e_reflect2d
#define e_reflect3 e_reflect3d
#define e_project2 e_project2d
#define e_project3 e_project3d
#define e_intersect2 e_intersect2d
#define e_matrix_clear e_matrix_cleard
#define e_transform3 e_transform3d
#define e_transform4 e_transform4d
#define e_matrix_multiply e_matrix_multiplyd
#define e_matrixxy e_matrixxyd
#define e_matrixxz e_matrixxzd
#define e_matrixyx e_matrixyxd
#define e_matrixyz e_matrixyzd
#define e_matrixzx e_matrixzxd
#define e_matrixzy e_matrixzyd
#define e_spline e_splined
#define e_spline2d e_spline2dd
#define e_spline3d e_spline3dd
#define e_spline4d e_spline4dd
#define e_wiggle e_wiggled
#define e_wiggle2d e_wiggle2dd
#define e_wiggle3d e_wiggle3dd
#define e_smooth_step e_smooth_stepd
#define e_noise e_noised
#define e_noise2 e_noise2d
#define e_noise3 e_noise3d
#define e_noiser e_noiserd
#define e_noiser2 e_noiser2d
#define e_noiser3 e_noiser3d
#define e_step e_stepd

#else

#define e_length2 e_length2f
#define e_length3 e_length3f
#define e_distance2 e_distance2f
#define e_distance3 e_distance3f
#define e_dot2 e_dot2f
#define e_dot3 e_dot3f
#define e_cross2 e_cross2f
#define e_cross3 e_cross3f
#define e_normalize2 e_normalize2f
#define e_normalize3 e_normalize3f
#define e_normalize4 e_normalize4f
#define e_reflect2 e_reflect2f
#define e_reflect3 e_reflect3f
#define e_project2 e_project2f
#define e_project3 e_project3f
#define e_intersect2 e_intersect2f
#define e_matrix_clear e_matrix_clearf
#define e_transform3 e_transform3f
#define e_transform4 e_transform4f
#define e_matrix_multiply e_matrix_multiplyf
#define e_matrixxy e_matrixxyf
#define e_matrixxz e_matrixxzf
#define e_matrixyx e_matrixyxf
#define e_matrixyz e_matrixyzf
#define e_matrixzx e_matrixzxf
#define e_matrixzy e_matrixzyf
#define e_spline e_splinef
#define e_spline2d e_spline2df
#define e_spline3d e_spline3df
#define e_spline4d e_spline4df
#define e_wiggle e_wigglef
#define e_wiggle2d e_wiggle2df
#define e_wiggle3d e_wiggle3df
#define e_smooth_step e_smooth_stepf
#define e_noise e_noisef
#define e_noise2 e_noise2f
#define e_noise3 e_noise3f
#define e_noiser e_noiserf
#define e_noiser2 e_noiser2f
#define e_noiser3 e_noiser3f
#define e_step e_stepf

#endif // E_DOUBLE_PRECISION

#endif // _ENIGMA_H

