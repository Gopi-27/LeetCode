import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    p = products.fillna(0)
    return p
    