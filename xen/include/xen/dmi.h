#ifndef __DMI_H__
#define __DMI_H__

enum dmi_field {
	DMI_NONE,
	DMI_BIOS_VENDOR,
	DMI_BIOS_VERSION,
	DMI_BIOS_DATE,
	DMI_SYS_VENDOR,
	DMI_PRODUCT_NAME,
	DMI_PRODUCT_VERSION,
	DMI_BOARD_VENDOR,
	DMI_BOARD_NAME,
	DMI_BOARD_VERSION,
	DMI_STRING_MAX,
};

/*
 *	DMI callbacks for problem boards
 */
struct dmi_strmatch {
	u8 slot;
	const char *substr;
};

struct dmi_system_id {
	int (*callback)(const struct dmi_system_id *d);
	const char *ident;
	struct dmi_strmatch matches[4];
	void *driver_data;
};

#define DMI_MATCH(a,b)	{ a, b }

extern int dmi_check_system(const struct dmi_system_id *list);
extern void dmi_scan_machine(void);
extern const char *dmi_get_table(paddr_t *base, u32 *len);
extern void dmi_efi_get_table(const void *smbios, const void *smbios3);
bool dmi_get_date(int field, int *yearp, int *monthp, int *dayp);
extern void dmi_end_boot(void);

#endif	/* __DMI_H__ */
