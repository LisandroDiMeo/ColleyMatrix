import numpy as np
import pandas as pd

def transformToColley(data, home_team_cols, away_team_cols, id_col):
  if not all(elem in data.columns for elem in home_team_cols):
    print("Error, home_team_cols not found in data.")
    pass
  if not all(elem in data.columns for elem in away_team_cols):
    print("Error, away_teams_cols not found in data.")
    pass
  # first, we'll try to create a dict like this : a = {b : L, c : W, d : L, ... so on}
  home_team = home_team_cols[0]
  home_team_score = home_team_cols[1]
  away_team = away_team_cols[0]
  away_team_score = away_team_cols[1]
  
  teams = pd.unique(np.concatenate([pd.unique(data[home_team]), pd.unique(data[away_team])]))

  dicts = {}
  for team in teams:
    dicts[team] = {"wins" : 0, "losses": 0, "games": 0}
  # TODO: Remove draws!!!

  # Count wins and games between other teams
  for index, row in data.iterrows():
    winner = row[home_team] if row[home_team_score] > row[away_team_score] else row[away_team]
    losser = row[away_team] if winner == row[home_team] else row[home_team]
    dicts[winner][losser] = 1 if dicts[winner].get(losser) == None else dicts[winner][losser] + 1
    dicts[losser][winner] = 1 if dicts[losser].get(winner) == None else dicts[losser][winner] + 1
    dicts[winner]["wins"] = dicts[winner]["wins"] + 1
    dicts[losser]["losses"] = dicts[losser]["losses"] + 1
    dicts[winner]["games"] = dicts[winner]["games"] + 1
    dicts[losser]["games"] = dicts[losser]["games"] + 1
  rows = []
  b = []
  curr_ind = 0
  for team in teams:
    r = np.zeros( len(teams) )
    r[curr_ind] = dicts[team]["games"] + 2
    b.append(1 + (dicts[team]["wins"] - dicts[team]["losses"]) / 2)
    for i in range(0,len(teams)):
      if i != curr_ind:
        r[i] = 0 if dicts[team].get(teams[i]) == None else dicts[team][teams[i]] * -1
    rows.append(r)
    curr_ind = curr_ind + 1
  return dicts, np.stack(rows), b

  