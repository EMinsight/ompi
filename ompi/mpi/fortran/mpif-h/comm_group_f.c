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
#pragma weak PMPI_COMM_GROUP = ompi_comm_group_f
#pragma weak pmpi_comm_group = ompi_comm_group_f
#pragma weak pmpi_comm_group_ = ompi_comm_group_f
#pragma weak pmpi_comm_group__ = ompi_comm_group_f

#pragma weak PMPI_Comm_group_f = ompi_comm_group_f
#pragma weak PMPI_Comm_group_f08 = ompi_comm_group_f
#elif OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (PMPI_COMM_GROUP,
                           pmpi_comm_group,
                           pmpi_comm_group_,
                           pmpi_comm_group__,
                           pompi_comm_group_f,
                           (MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr),
                           (comm, group, ierr) )
#endif

#if OPAL_HAVE_WEAK_SYMBOLS
#pragma weak MPI_COMM_GROUP = ompi_comm_group_f
#pragma weak mpi_comm_group = ompi_comm_group_f
#pragma weak mpi_comm_group_ = ompi_comm_group_f
#pragma weak mpi_comm_group__ = ompi_comm_group_f

#pragma weak MPI_Comm_group_f = ompi_comm_group_f
#pragma weak MPI_Comm_group_f08 = ompi_comm_group_f
#endif

#if ! OPAL_HAVE_WEAK_SYMBOLS && ! OMPI_PROFILE_LAYER
OMPI_GENERATE_F77_BINDINGS (MPI_COMM_GROUP,
                           mpi_comm_group,
                           mpi_comm_group_,
                           mpi_comm_group__,
                           ompi_comm_group_f,
                           (MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr),
                           (comm, group, ierr) )
#endif


#if OMPI_PROFILE_LAYER && ! OPAL_HAVE_WEAK_SYMBOLS
#define ompi_comm_group_f pompi_comm_group_f
#endif


void ompi_comm_group_f(MPI_Fint *comm, MPI_Fint *group, MPI_Fint *ierr)
{
    int c_ierr;
    MPI_Group c_group;
    MPI_Comm c_comm = PMPI_Comm_f2c( *comm );

    c_ierr = PMPI_Comm_group( c_comm, &c_group);
    if (NULL != ierr) *ierr = OMPI_INT_2_FINT(c_ierr);

    if (MPI_SUCCESS == c_ierr) {
        *group = PMPI_Group_c2f (c_group);
    }
}
