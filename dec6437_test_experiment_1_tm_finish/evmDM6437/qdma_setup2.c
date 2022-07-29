/*
 * ======== qdma_setup.c ========
 *
 */

#define QDMA_BASE_ADDRESS  (0x01C00000)

/*
 * ======== qdma_setup ========
 */
void qdma_setup(void) 
{
   unsigned int qdmaBaseAddr = QDMA_BASE_ADDRESS;
   volatile unsigned int *QDMAQNUM = (volatile unsigned int *)(qdmaBaseAddr + 0x0260);
   volatile unsigned int *QUETCMAP = (volatile unsigned int *)(qdmaBaseAddr + 0x0280);
   volatile unsigned int *QUEPRI   = (volatile unsigned int *)(qdmaBaseAddr + 0x0284);
   unsigned int chan, i;

   /* Associate QDMA channels to Q1 */
   for (i = 0; i < 8; i++) {
       chan = i;
       *QDMAQNUM = ((*QDMAQNUM) | (0x1 << (4 * chan)));
   }

   /* Associate QDAM queues to TCs */
   *QUETCMAP = (0x1 << 4) | (0x0);

   /* Set priority of 7 (low) to Q1 and hence low priority to QDMA channels.*/
   *QUEPRI   = (0x7 << 4) | (0x3);
}

