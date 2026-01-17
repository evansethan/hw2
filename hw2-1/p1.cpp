/*
- Last week we mentioned std::copy. There is a related function in the
<algorithm> header called std::transform, which lets you apply a function
to each element before copying. Look up or Google for std::transform to
understand the precise usage.
- Write a program that puts several doubles in a vector and then uses
std::transform to produce a new vector with each element equal to the square
of the corresponding element in the original vector and print the new vector
(If you use ostream_iterator to print the new vector, you will likely get an
extra comma at the end of the output. Don’t worry if that happens).
*/
