#ifndef EXERCISE_HPP
#define EXERCISE_HPP


/**
 * @brief exercise function to demonstrate iterator invalidation and safe vector modification.
 *
 * @details This function initializes a vector of integers and iterates through it.
 * When an odd number is encountered, a duplicate of that number is inserted
 * at the current iterator position. The iterator is then correctly updated
 * with the new iterator returned by the `std::vector::insert` call.
 * The loop includes a counter (`temp`) to ensure it terminates and avoids an
 * infinite loop scenario if all inserted elements were also odd.
 *
 * @return EXIT_SUCCESS on successful execution.
 * 
 */

int exercise();

#endif // EXERCISE_HP