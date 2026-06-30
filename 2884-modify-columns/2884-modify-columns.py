import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["salary"].to_numpy(copy=False)[:] *= 2
    return employees