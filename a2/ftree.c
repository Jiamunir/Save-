#include <stdio.h>
// Add your system includes here.

#include "ftree.h"
#include "hash.h"

/*a recursive function that creates fills in TreeNode, given a starting node
*/
struct TreeNode *fill_node(const char* path){

struct stat *buff;
	if(lstat(path, buff) != 0){ //error
		printf("%s\n", sterror(errno));
	}else{
		struct TreeNode new_node;
		/*set name */
		char *extract_name = strrchar(path, '/'); //last occurrence of '/'
		int num_char_to_cpy = path[strlen(path) -1] - extract_name; //calculating length of name 
		strncpy(new_node.fname, (extract_name + 1), num_char_to_cpy);	
	
		/*set permissions*/
		new_node.persissions = ((buff -> st_mode) & 0777); 	
		
		/*	set contents if directory, set hash if file or link*/
		if(!S_ISDIR(buff -> st_mode)){ //file or link
			new_node.contents = NULL;
			new_node.hash = hash(path); //strcpy or is this okay??
		}else {
			new_node.hash = NULL;
			struct dirent *dp;
			
						
			}
			
	}
}

/*
 * Returns the FTree rooted at the path fname.
 */
struct TreeNode *generate_ftree(const char *fname) {
    // Your implementation here.
    return NULL;
}


/*
 * Prints the TreeNodes encountered on a preorder traversal of an FTree.
 */
void print_ftree(struct TreeNode *root) {
    // Here's a trick for remembering what depth (in the tree) you're at
    // and printing 2 * that many spaces at the beginning of the line.
    static int depth = 0;
    printf("%*s", depth * 2, "");

    // Your implementation here.
}
