#include "core/abys_utils.h"







#define ERR_MSG_LEN 256


// Last error storage
static char g_last_error[ERR_MSG_LEN] = "";


// Set/overwrite the last error
void abys_SetError(const char* msg) {
    strncpy(g_last_error, msg, ERR_MSG_LEN - 1);
    g_last_error[ERR_MSG_LEN - 1] = '\0'; // safety null-termination
}


// Clear the last error
void abys_ResetError() {
    g_last_error[0] = '\0';
}


// Get the last error (returns NULL if empty)
const char* abys_GetError() {
    return g_last_error[0] ? g_last_error : " ";
}