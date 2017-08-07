/* -*- coding: utf-8 -*-
 ###############################################################################
 # Author: Pierre Vigneras <pierre.vigneras@bull.net>
 # Created on: May 24, 2013
 # Contributors:
 ###############################################################################
 # Copyright (C) 2012  Bull S. A. S.  -  All rights reserved
 # Bull, Rue Jean Jaures, B.P.68, 78340, Les Clayes-sous-Bois
 # This is not Free or Open Source software.
 # Please contact Bull S. A. S. for details about its license.
 ###############################################################################
 */


#include "bxi/base/err.h"
#include "bxi/base/mem.h"
#include "bxi/base/str.h"
#include "bxi/base/time.h"
#include "bxi/base/zmq.h"

#include "bxi/base/log.h"

#include "tsd_impl.h"


//*********************************************************************************
//********************************** Defines **************************************
//*********************************************************************************

//*********************************************************************************
//********************************** Types ****************************************
//*********************************************************************************


//*********************************************************************************
//********************************** Static Functions  ****************************
//*********************************************************************************


//*********************************************************************************
//********************************** Global Variables  ****************************
//*********************************************************************************

//*********************************************************************************
//********************************** Implementation    ****************************
//*********************************************************************************


bxierr_p bxilog_set_thread_rank(uintptr_t rank) {
    tsd_p tsd;
    bxierr_p err = bxilog__tsd_get(&tsd);
    if (bxierr_isko(err)) return err;
    tsd->thread_rank = rank;
    return BXIERR_OK;
}

bxierr_p bxilog_get_thread_rank(uintptr_t * rank_p) {
    tsd_p tsd;
    bxierr_p err = bxilog__tsd_get(&tsd);
    if (bxierr_isko(err)) return err;
    *rank_p = tsd->thread_rank;
    return BXIERR_OK;
}

//*********************************************************************************
//********************************** Static Helpers Implementation ****************
//*********************************************************************************

