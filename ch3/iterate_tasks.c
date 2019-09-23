#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

struct task_struct *task;

int iterate_tasks_init(void) {
    printk(KERN_INFO "Loading Kernel Module\n");
    for_each_process(task) {
        printk("task command: %s, state: %li, process id: %d\n", task->comm, task->state, task->pid); 
    }
    return 0;
}

void iterate_tasks_exit(void) {
    printk(KERN_INFO "Removing Kernel Module\n");
}

module_init(iterate_tasks_init);
module_exit(iterate_tasks_exit);

