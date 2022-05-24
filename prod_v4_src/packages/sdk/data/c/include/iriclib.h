#include "iriclib_global.h"

#define IRIC_MODE_READ          0
#define IRIC_MODE_WRITE         1
#define IRIC_MODE_MODIFY        2

#define IRIC_GEO_UNKNOWN        0
#define IRIC_GEO_POLYGON        1
#define IRIC_GEO_RIVERSURVEY    2
#define IRIC_GEO_POINTMAP       3
#define IRIC_GEO_POLYLINE       4

#define IRIC_OPTION_UNKNOWN         0
#define IRIC_OPTION_CANCEL          1
#define IRIC_OPTION_DIVIDESOLUTIONS 2
#define IRIC_OPTION_STDSOLUTION     3

#define IRIC_LOCKED 1

#define IRIC_CANCELED 1

#define IRIC_POLYDATA_POLYGON  1
#define IRIC_POLYDATA_POLYLINE 2

#include "iriclib_bc.h" // boundary condition
#include "iriclib_cc.h" // calculation condition
#include "iriclib_combine.h" // combine
#include "iriclib_complex.h" // complex grid attribute
#include "iriclib_errorcodes.h" // error codes
#include "iriclib_geo.h" // geographic data
#include "iriclib_geoutil.h" // geographic data
#include "iriclib_grid.h" // grid coordinates and attributes
#include "iriclib_grid_solverlib.h" // iricsolverlib
#include "iriclib_gui_coorp.h" // gui coorporation
#include "iriclib_init.h" // initialization and finalization
#include "iriclib_solution.h" // solution basis
#include "iriclib_sol_cell.h" // solution at cell
#include "iriclib_sol_gridcoord.h" // grid coordinstes for solution
#include "iriclib_sol_iface.h" // solution at iface
#include "iriclib_sol_jface.h" // solution at jface
#include "iriclib_sol_kface.h" // solution at kface
#include "iriclib_sol_node.h" // solution at node
#include "iriclib_sol_particle.h" // solution at particles
#include "iriclib_sol_particlegroup.h" // solution at particle groups
#include "iriclib_sol_polydata.h" // solution at lines, polygons
#include "iriclib_not_withbaseid.h" // not withbaseid
#include "iriclib_not_withgridid.h" // not withgridid
