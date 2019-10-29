/* SPDX-License-Identifier: GPL-2.0+ */

#ifndef __PXE_UTILS_H
#define __PXE_UTILS_H

/*
 * Describes a pxe menu as given via pxe files.
 *
 * title - the name of the menu as given by a 'menu title' line.
 * default_label - the name of the default label, if any.
 * bmp - the bmp file name which is displayed in background
 * timeout - time in tenths of a second to wait for a user key-press before
 *           booting the default label.
 * prompt - if 0, don't prompt for a choice unless the timeout period is
 *          interrupted.  If 1, always prompt for a choice regardless of
 *          timeout.
 * labels - a list of labels defined for the menu.
 */
struct pxe_menu {
	char *title;
	char *default_label;
	char *bmp;
	int timeout;
	int prompt;
	struct list_head labels;
};

extern bool is_pxe;

extern int (*do_getfile)(cmd_tbl_t *cmdtp, const char *file_path,
			 char *file_addr);
void destroy_pxe_menu(struct pxe_menu *cfg);
int get_pxe_file(cmd_tbl_t *cmdtp, const char *file_path,
		 unsigned long file_addr);
int get_pxelinux_path(cmd_tbl_t *cmdtp, const char *file,
		      unsigned long pxefile_addr_r);
void handle_pxe_menu(cmd_tbl_t *cmdtp, struct pxe_menu *cfg);
struct pxe_menu *parse_pxefile(cmd_tbl_t *cmdtp, unsigned long menucfg);
int pxe_ipaddr_paths(cmd_tbl_t *cmdtp, unsigned long pxefile_addr_r);
int pxe_mac_path(cmd_tbl_t *cmdtp, unsigned long pxefile_addr_r);
int pxe_uuid_path(cmd_tbl_t *cmdtp, unsigned long pxefile_addr_r);

#endif /* __PXE_UTILS_H */
