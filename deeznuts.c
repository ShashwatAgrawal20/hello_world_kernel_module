#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init deeznuts_entered(void) {
    printk(KERN_INFO "ENTERED\n");
    return 0;
}

static void __exit deeznuts_exited(void) { printk(KERN_INFO "EXITED\n"); }

module_init(deeznuts_entered);
module_exit(deeznuts_exited);
