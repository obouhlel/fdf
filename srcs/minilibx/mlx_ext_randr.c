


#include	"../../includes/mlx_int.h"

#include	<unistd.h>
#include <X11/extensions/Xrandr.h>

/* global for independant extension */

RRMode	saved_mode = 0;


int			mlx_ext_fullscreen(t_xvar *xvar, t_win_list *win, int fullscreen)
{
  XWindowAttributes	watt;
  int			i;
  int			j;
  XRRScreenResources	*res;
  XRROutputvars		*o_vars;
  XRRCrtcvars		*crtc;
  RRMode		mode_candidate;
  int			idx_output;
  int			idx_candidate;

  if (!XGetWindowAttributes(xvar->display, win->window, &watt))
    return (0);

  res = XRRGetScreenResources(xvar->display, xvar->root);
  o_vars = NULL;
  idx_output = -1;
  i = res->noutput;
  while (i--)
    {
      o_vars = XRRGetOutputvars(xvar->display, res, res->outputs[i]);
      if (o_vars->connection == RR_Connected)
	{
	  idx_output = i;
	  i = 0;
	}
      else
	XRRFreeOutputvars(o_vars);
    }
  if (!o_vars)
    {
      XRRFreeScreenResources(res);
      return (0);
    }
  
  idx_candidate = -1;
  i = o_vars->nmode;
  while (i--)
    {
      j = res->nmode;
      while (j--)
	if (res->modes[j].id == o_vars->modes[i])
	  if (res->modes[j].width >= watt.width && res->modes[j].height >= watt.height &&
	      (idx_candidate == -1 || res->modes[idx_candidate].width > res->modes[j].width ||
	       res->modes[idx_candidate].height > res->modes[j].height) )
	    idx_candidate = i;
    }
  if (idx_candidate < 0)
    {
      XRRFreeOutputvars(o_vars);
      XRRFreeScreenResources(res);
      return (0);
    }
  if (!fullscreen && saved_mode == -1)
    idx_candidate = 0; /* if no clue, uses first mode, usually part of npreferred */
  mode_candidate = o_vars->modes[idx_candidate];
  if (!fullscreen)
    mode_candidate = saved_mode;

  crtc = XRRGetCrtcvars(xvar->display, res, o_vars->crtc);
  saved_mode = crtc->mode;

  i = XRRSetCrtcConfig(xvar->display, res, o_vars->crtc, CurrentTime, 0, 0, mode_candidate,
		       crtc->rotation, &res->outputs[idx_output], 1);
  if (fullscreen)
    printf("found mode : %d x %d\n Status %d\n", res->modes[idx_candidate].width, res->modes[idx_candidate].height, i);
  else
    printf("back previous mode\n");
  
  XMoveWindow(xvar->display, win->window, 0, 0);
  XMapRaised(xvar->display, win->window);

  if (fullscreen)
    {
      //      XGrabPointer(xvar->display, win->window, True, 0, GrabModeAsync, GrabModeAsync, win->window, 0L, CurrentTime);
      XGrabKeyboard(xvar->display, win->window, False, GrabModeAsync, GrabModeAsync, CurrentTime);
    }
  else
    {
      XUngrabPointer(xvar->display, CurrentTime);
      XUngrabKeyboard(xvar->display, CurrentTime);
    }

  XSync(xvar->display, False);
  sleep(1);

  XRRFreeCrtcvars(crtc);
  XRRFreeOutputvars(o_vars);
  XRRFreeScreenResources(res);
}
