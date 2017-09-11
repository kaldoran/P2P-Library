//----------------------------------------------------------
// AUTEUR : REYNAUD Nicolas                                 |
// FICHIER : verification.h                                 |
//----------------------------------------------------------

#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <stdio.h>

#include "boolean.h"

/** Verifies that a file exists or not.
 * 
 *  %param filename: Path of the file to verify.
 *  %return: TRUE if the file exist,
 *           FALSE otherwise.
 */
bool file_exist(const char *_filename);

/** Funtion to verify the user imput for the ip.
 *  %param _ip : Ip adresse to verify.
 *  %return : If ip adresse is valide then TRUE,
 *            else FALSE.
 */
bool verif_ip(const char* _ip);

/** Funtion to verify the user imput for the port.
 *  %param port : Port to verify.
 *  %return : If valid port then TRUE,
 *            else FALSE.
 */
bool verif_port(int _port);

#endif /* VERIFICATION_H included */
