/* a simple kernel module */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* module information
 * Compiler puts these information in .modinfo section of the kernel module
 * object file. Some information affects the loading behavior.
 */
#define DRV_DESC                                                               \
	"A basic Linux Kernel Module demonstration. "                          \
	"User can enter an user name argument."
MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Immortal Jellyfish");
MODULE_DESCRIPTION(DRV_DESC);
MODULE_VERSION("0.1");

/* module parameter declaration */
#define DEFAULT_NAME "world"
#define PARAM_DESC_NAME                                                        \
	"The user name used in this module, or " DEFAULT_NAME " by default"
static char *name = DEFAULT_NAME;
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, PARAM_DESC_NAME);

/* formated print message
 * The macro pr_fmt defines the behavior of pr_info. Their definitions are
 * in linux/printk.h
 */
#undef pr_fmt
#define pr_fmt(fmt) "%s %d:" fmt, __func__, __LINE__

/* __init tells compiler that this function is only called during module
 * insertion. So, compiler would make memory optimization for this function.
 */
static int __init hello_init(void)
{
	pr_info("Hello %s!\n", name);
	return 0;
}

/* __exit tells compiler that this function is only called during module
 * removing. So, compiler would make memory optimization for this function.
 */
static void __exit hello_exit(void)
{
	pr_info("Goodbye %s!\n", name);
}

/* 2 macros determine the exact initialization function of the kernel module,
 * and the exact destruction function of the kernel module. Each module can
 * only has exact one pair of these macros.
 */
module_init(hello_init);
module_exit(hello_exit);
