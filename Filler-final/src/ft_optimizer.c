#include "../inc/filler.h"

static int		ft_get_actl_pce_t(t_input *d)
{
	int		pce_t;
	int		cntr_rw;
	int		cntr_cl;

	pce_t = 0;
	cntr_rw = 0;
	while (cntr_rw < d->p_rws)
	{
		cntr_cl = 0;
		while (cntr_cl < d->p_cls)
		{
			if (d->p[cntr_rw][cntr_cl] == '*')
				pce_t = cntr_rw;
			if (d->p[cntr_rw][cntr_cl] == '*')
				return (pce_t);
			++cntr_cl;
		}
		++cntr_rw;
	}
	return (pce_t);
}

static int		ft_get_actl_pce_b(t_input *d)
{
	int		pce_b;
	int		cntr_rw;
	int		cntr_cl;

	pce_b = 0;
	cntr_rw = d->p_rws - 1;
	while (cntr_rw > -1)
	{
		cntr_cl = d->p_cls - 1;
		while (cntr_cl > -1)
		{
			if (d->p[cntr_rw][cntr_cl] == '*')
				pce_b = cntr_rw;
			if (d->p[cntr_rw][cntr_cl] == '*')
				return (pce_b);
			--cntr_cl;
		}
		--cntr_rw;
	}
	return (pce_b);
}

static int		ft_get_actl_pce_l(t_input *d)
{
	int		pce_l;
	int		cntr_rw;
	int		cntr_cl;

	pce_l = 0;
	cntr_cl = 0;
	while (cntr_cl < d->p_cls)
	{
		cntr_rw = 0;
		while (cntr_rw < d->p_rws)
		{
			if (d->p[cntr_rw][cntr_cl] == '*')
				pce_l = cntr_cl;
			if (d->p[cntr_rw][cntr_cl] == '*')
				return (pce_l);
			++cntr_rw;
		}
		++cntr_cl;
	}
	return (pce_l);
}

static int		ft_get_actl_pce_r(t_input *d)
{
	int		pce_r;
	int		cntr_rw;
	int		cntr_cl;

	pce_r = 0;
	cntr_cl = d->p_cls - 1;
	while (cntr_cl > -1)
	{
		cntr_rw = d->p_rws - 1;
		while (cntr_rw > -1)
		{
			if (d->p[cntr_rw][cntr_cl] == '*')
				pce_r = cntr_cl;
			if (d->p[cntr_rw][cntr_cl] == '*')
				return (pce_r);
			--cntr_rw;
		}
		--cntr_cl;
	}
	return (pce_r);
}

t_midpos		ft_optmze(t_input *d, t_move *n)
{
	int			p_t;
	int			p_b;
	int			p_l;
	int			p_r;
	t_midpos	p_mid;

	p_t = ft_get_actl_pce_t(d);
	p_b = ft_get_actl_pce_b(d);
	p_l = ft_get_actl_pce_l(d);
	p_r = ft_get_actl_pce_r(d);
	p_mid.rw = n->row + ((p_t + p_b) / 2);
	p_mid.cl = n->col + ((p_l + p_r) / 2);
	return (p_mid);
}