### xargs-serial
Written by Wim R.M. Cardoen

1. Invoke build.sh to build the executable 'main'
2. Change the following lines:
   - #SBATCH --account=chpc -> Modify it to your own account 
   - export WORK_DIR=~/xargs-serial
3. Submit the job:
     sbatch simul.sl
