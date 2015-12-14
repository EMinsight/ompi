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

#if OPAL_HAVE_WEAK_SYMBOLS && OMPI_PROFILE_LAYER
#pragma weak PMPI_INFO_GET_NKEYS = ompi_info_get_nkeys_f
#pragma weak pmpi_info_get_nkeys = ompi_info_get_nkeys_f
#pragma weak pmpi_info_get_nkeys_ = ompi_info_get_nkeys_f
#pragma weak pmpi_info_get_nkeys__ = ompi_info_get_nkeys_f

#pragma weak PMPI_Info_get_nkeys_f = ompi_info_get_nkeys_f
#pragma weak PMPI_Info_get_nkeys_f08 = ompi_info_get_nkeys_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_INFO_GET_NKEYS,
                           pmpi_info_get_nkeys,
                           pmpi_info_get_nkeys_,
                           pmpi_info_get_nkeys__,
                           pompi_info_get_nkeys_f,
                           (MPI_Fint *info, MPI_Fint *nkeys, MPI_Fint *ierr),
                           (info, nkeys, ierr) )
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_INFO_GET_NKEYS = ompi_info_get_nkeys_f
#pragma weak mpi_info_get_nkeys = ompi_info_get_nkeys_f
#pragma weak mpi_info_get_nkeys_ = ompi_info_get_nkeys_f
#pragma weak mpi_info_get_nkeys__ = ompi_info_get_nkeys_f

#pragma weak MPI_Info_get_nkeys_f = ompi_info_get_nkeys_f
#pragma weak MPI_Info_get_nkeys_f08 = ompi_info_get_nkeys_f
#endif

#if ! OPAL_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_INFO_GET_NKEYS,
                           mpi_info_get_nkeys,
                           mpi_info_get_nkeys_,
                           mpi_info_get_nkeys__,
                           ompi_info_get_nkeys_f,
                           (MPI_Fint *info, MPI_Fint *nkeys, MPI_Fint *ierr),
                           (info, nkeys, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OPAL_HAVE_WEAK_SYMBOLS
#define ompi_info_get_nkeys_f pompi_info_get_nkeys_f
#endif


void ompi_info_get_nkeys_f(MPI_Fint *info, MPI_Fint *nkeys, MPI_Fint *ierr)
{
    int c_ierr;
    MPI_Info c_info;
    OMPI_SINGLE_NAME_DECL(nkeys);

    c_info = PMPI_Info_f2c(*info);

    c_ierr = PMPI_Info_get_nkeys(c_info, OMPI_SINGLE_NAME_CONVERT(nkeys));
    if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);

    if (MPI_SUCCESS == c_ierr) {
        OMPI_SINGLE_INT_2_FINT(nkeys);
    }
}
