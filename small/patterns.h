#ifndef __PATTERNS__H
#define __PATTERNS__H

/* rotating columns */
void rotate(int size);

/* pattern of moving rows */
void switchingRows();
void reverseSwitchingRows();

/* complement of switchingRows() */
void switchingEmptyRows();
void reverseSwitchingEmptyRows();

/* fill up the cube one LED at a time */
void fillingUp();

// TODO: unimplemented patterns
void randomWalk();
void rain();
void plague();
void randomLights();

#endif

