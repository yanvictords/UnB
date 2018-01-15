--Questão 28
qualAnimal = do
  putStrLn "Qual animal você viu? (Responda as perguntas com 'S' ou 'N')"
  -- A resposta Padrão é não, logo qualquer coisa diferente de s ou S será
  -- considerado não
  putStrLn "O animal era um mamífero?(s/N)"
  resposta <- getLine
  if (elem resposta ["s","S"]) then do
    putStrLn "O animal era carnívoro?(s/N)"
    resposta <- getLine
    if (elem resposta ["s","S"]) then do
      putStrLn "O animal era de cor amarelada?(s/N)"
      resposta <- getLine
      if (elem resposta ["s","S"]) then do
        putStrLn "O animal possuía manchas pretas?(s/N)"
        resposta <- getLine
        if (elem resposta ["s","S"]) then do
          putStrLn "O animal é um Guepardo!"
        else do
          putStrLn "O animal possuía listas pretas?(s/N)"
          resposta <- getLine
          if (elem resposta ["s","S"]) then do
            putStrLn "O animal é um Tigre!"
          else do
            putStrLn "Animal desconhecido."
      else do
        putStrLn "Animal desconhecido."
    else do
      putStrLn "O animal era ungulado?(s/N)"
      resposta <- getLine
      if (elem resposta ["s","S"]) then do
          putStrLn "O animal tinha pescoço grande?(s/N)"
          resposta <- getLine
          if (elem resposta ["s","S"]) then do
            putStrLn "O animal tinha pernas grandes?(s/N)"
            resposta <- getLine
            if (elem resposta ["s","S"]) then do
                putStrLn "O animal é uma Girafa!"
            else do
                putStrLn "Animal desconhecido."
          else do
              putStrLn "O animal tinha listras pretas?(s/N)"
              resposta <- getLine
              if (elem resposta ["s","S"]) then do
                  putStrLn "O animal é uma Zebra!"
              else do
                  putStrLn "Animal desconhecido."
      else do
          putStrLn "Animal desconhecido"
  else do
    putStrLn "O animal era uma ave?(s/N)"
    resposta <- getLine
    if (elem resposta ["s","S"]) then do
      putStrLn "O animal voa?(s/N)"
      resposta <- getLine
      if (elem resposta ["s","S"]) then do
        putStrLn "O animal tinha longas asas?(s/N)"
        resposta <- getLine
        if (elem resposta ["s","S"]) then do
          putStrLn "O animal é um Albatroz!"
        else do
          putStrLn "Animal desconhecido."
      else do
        putStrLn "O animal possuia um pescoço comprido?(s/N)"
        resposta <- getLine
        if (elem resposta ["s","S"]) then do
          putStrLn "O animal é um Avestruz!"
        else do
          putStrLn "O animal nadava?(s/N)"
          resposta <- getLine
          if (elem resposta ["s","S"]) then do
            putStrLn "O animal era preto e branco?(s/N)"
            resposta <- getLine
            if (elem resposta ["s","S"]) then do
              putStrLn "O animal é um Pinguim!"
            else do
              putStrLn "Animal desconhecido"
          else do
            putStrLn "Animal desconhecido"
    else do
      putStrLn "Animal desconhecido."
