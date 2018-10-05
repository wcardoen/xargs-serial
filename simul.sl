#!/bin/bash

#SBATCH --time=12:00:00
#SBATCH --nodes=1
#SBATCH --ntasks=12
#SBATCH --account=chpc
#SBATCH --partition=ember
#SBATCH --job-name=MC-Simul

# Env. variables
#   NUM_SIM : Number of Independent Calculations
#   NUM_ITER: Number of Steps for each MC calculation
#   OUT_DIR : Directory where results will be stored
#   FILENAME: Each results will be Stored in $OUT_DIR/FILENAME.$ITER.txt
export WORK_DIR=~/xargs-serial
export NUM_SIM=40  
export NUM_ITER=100000000        
export OUT_DIR=$WORK_DIR/$SLURM_JOBID
export FILENAME=mcout

# The node has SLURM_NTASKS (i.e. cores)
# Each core will launch the script ./myprog.sh folled by some parameters
# The calculations will be launched in batches of $SLURM_NTASKS
echo " Calc. started on `date`"
mkdir -p $OUT_DIR
cd $WORK_DIR
seq 1 $NUM_SIM | xargs -n 1  -P $SLURM_NTASKS ./myprog.sh $NUM_ITER $OUT_DIR/$FILENAME  >& $SLURM_JOBID.out
echo " Calc. ended at `date`"
