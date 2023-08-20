#!/usr/bin/python3

import yfinance as yf
import argparse
from datetime import datetime, timedelta

def show_mon_avg_price(tickerSymbol, start, end):
    data = yf.Ticker(tickerSymbol)
    df = data.history(period='1d', start=start, end=end)
    monthly_avg = df.resample('M').mean()
    
    print("Date Ticker AveragePrice")
    for date, row in monthly_avg.iterrows():
        print(f"{date.strftime('%Y-%m')} {tickerSymbol} {row['Close']:.2f}")

def main(args):
    # Use input tickers if provided, otherwise use the default list
    tickers = args.tickers if args.tickers else ['A', 'AMD', 'GOOG', 'TSM', 'WBD']

    # Last month.
    end = datetime(datetime.today().year, datetime.today().month, 1) - timedelta(days=1)
    # Specified number of years before the end date.
    start = datetime(end.year - args.years, (end.month + 1) % 12, 1)

    for t in tickers:
        show_mon_avg_price(t, start.strftime('%Y-%m-%d'), end.strftime('%Y-%m-%d'))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Show average monthly stock prices.')
    parser.add_argument('--tickers', nargs='+', help='List of ticker symbols')
    parser.add_argument('--years', type=int, default=1, help='Number of years before the end date')
    args = parser.parse_args()
    main(args)
