/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart,
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2011-2012 Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2015      Research Organization for Information Science
 *                         and Technology (RIST). All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "ompi_config.h"

#include "ompi/mpi/fortran/mpif-h/bindings.h"
#include "ompi/mpi/fortran/base/constants.h"

#if OPAL_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_FILE_IREAD_AT = ompi_file_iread_at_f
#pragma weak pmpi_file_iread_at = ompi_file_iread_at_f
#pragma weak pmpi_file_iread_at_ = ompi_file_iread_at_f
#pragma weak pmpi_file_iread_at__ = ompi_file_iread_at_f

#pragma weak PMPI_File_iread_at_f = ompi_file_iread_at_f
#pragma weak PMPI_File_iread_at_f08 = ompi_file_iread_at_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_FILE_IREAD_AT,
                            pmpi_file_iread_at,
                            pmpi_file_iread_at_,
                            pmpi_file_iread_at__,
                            pompi_file_iread_at_f,
                            (MPI_Fint *fh, MPI_Offset *offset, char *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr),
                            (fh, offset, buf, count, datatype, request, ierr) )
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_FILE_IREAD_AT = ompi_file_iread_at_f
#pragma weak mpi_file_iread_at = ompi_file_iread_at_f
#pragma weak mpi_file_iread_at_ = ompi_file_iread_at_f
#pragma weak mpi_file_iread_at__ = ompi_file_iread_at_f

#pragma weak MPI_File_iread_at_f = ompi_file_iread_at_f
#pragma weak MPI_File_iread_at_f08 = ompi_file_iread_at_f
#endif

#if ! OPAL_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
   OMPI_GENERATE_F77_BINDINGS (MPI_FILE_IREAD_AT,
                               mpi_file_iread_at,
                               mpi_file_iread_at_,
                               mpi_file_iread_at__,
                               ompi_file_iread_at_f,
                               (MPI_Fint *fh, MPI_Offset *offset, char *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr),
                               (fh, offset, buf, count, datatype, request, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OPAL_HAVE_WEAK_SYMBOLS
#define ompi_file_iread_at_f pompi_file_iread_at_f
#endif


void ompi_file_iread_at_f(MPI_Fint *fh, MPI_Offset *offset,
                         char *buf, MPI_Fint *count,
                         MPI_Fint *datatype, MPI_Fint *request, MPI_Fint *ierr)
{
   int c_ierr;
   MPI_File c_fh = PMPI_File_f2c(*fh);
   MPI_Datatype c_type = PMPI_Type_f2c(*datatype);
   MPI_Request c_request;

   c_ierr = PMPI_File_iread_at(c_fh, (MPI_Offset) *offset,
                              OMPI_F2C_BOTTOM(buf),
                              OMPI_FINT_2_INT(*count),
                              c_type,
                              &c_request);
   if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);

   if (MPI_SUCCESS == c_ierr) {
      *request = PMPI_Request_c2f(c_request);
   }
}
